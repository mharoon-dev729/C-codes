// ALL THE REASONINGS ARE WRITTEN IN WORD FILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <error.h>
// structure
typedef struct {
    char **lines;     // dynamic array of pointers
    size_t size;      // number of stored lines
    size_t capacity;  // allocated capacity for pointers
} Buffer;

#define INITIAL_CAPACITY 4
// exit on malloc/realloc failure with error message
static void die_malloc(const char *msg) {
    fprintf(stderr, "Memory error: %s: %s\n", msg, strerror(errno));
    exit(EXIT_FAILURE);
}
// initialize the buffer
void initBuffer(Buffer *b) {
    b->size = 0;
    b->capacity = INITIAL_CAPACITY;
    b->lines = malloc(b->capacity * sizeof(char*));
    if (!b->lines) die_malloc("malloc for lines array");
}
// free all strings and the pointer array
void freeAll(Buffer *b) {
	size_t i;
    for ( i = 0; i < b->size; ++i) {
        free(b->lines[i]);
    }
    free(b->lines);
    b->lines = NULL;
    b->size = 0;
    b->capacity = 0;
}
// ensure capacity for at least new_capacity pointers
void ensureCapacity(Buffer *b, size_t minCapacity) {
    if (b->capacity >= minCapacity) return;
    size_t newcap = b->capacity ? b->capacity * 2 : INITIAL_CAPACITY;
    while (newcap < minCapacity) newcap *= 2;
    char **tmp = realloc(b->lines, newcap * sizeof(char*));
    if (!tmp) die_malloc("realloc for lines array");
    b->lines = tmp;
    b->capacity = newcap;
}
// shrink-to-fit: reduce capacity to exactly size
void shrinkToFit(Buffer *b) {
    if (b->size == b->capacity) return; // already fit
    if (b->size == 0) {
        free(b->lines);
        b->lines = NULL;
        b->capacity = 0;
        return;
    }
    char **tmp = realloc(b->lines, b->size * sizeof(char*));
    if (!tmp) die_malloc("realloc in shrinkToFit");
    b->lines = tmp;
    b->capacity = b->size;
}
// read a line of arbitrary length from FILE* stream. Returns malloc'd string or NULL on EOF.
// the returned string will have the trailing newline removed (if present). Caller must free.
char *readLineFromStream(FILE *stream) {
    size_t cap = 128;
    size_t len = 0;
    char *buf = malloc(cap);
    if (!buf) die_malloc("malloc for read buffer");
    int c;
    while ((c = fgetc(stream)) != EOF) {
        if (c == '\r') continue; // ignore CR for windows-style endings
        if (len + 1 >= cap) {
            cap *= 2;
            char *tmp = realloc(buf, cap);
            if (!tmp) {
                free(buf);
                die_malloc("realloc for read buffer");
            }
            buf = tmp;
        }
        if (c == '\n') {
            break;  // line finished
        }
        buf[len++] = (char)c;
    }
    if (len == 0 && c == EOF) {
        free(buf);
        return NULL; // EOF with no data 
    }
    buf[len] = '\0';
    // shrink buffer to exact size
    char *final = realloc(buf, len + 1);
    if (!final) {
        // if realloc fails, keep original buffer; it's fine
        final = buf;
    }
    return final;
}
// insert a copy of text at position index (0..size). If index==size append at end.
// we allocate exact-sized memory for the new string (strlen+1).
void insertLine(Buffer *b, size_t index, const char *text) {
    if (index > b->size) {
        fprintf(stderr, "insertLine: invalid index %zu (size %zu)\n", index, b->size);
        return;
    }
    ensureCapacity(b, b->size + 1);
// shift pointers to make room (shift from index..size-1 right by 1)
    if (index < b->size) {
        memmove(&b->lines[index+1], &b->lines[index], (b->size - index) * sizeof(char*));
    }
    size_t textlen = strlen(text);
    char *copy = malloc(textlen + 1);
    if (!copy) die_malloc("malloc for new line");
    memcpy(copy, text, textlen + 1);
    b->lines[index] = copy;
    b->size++;
}
// delete the line at index and free its memory. Compact pointer array.
void deleteLine(Buffer *b, size_t index) {
    if (index >= b->size) {
        fprintf(stderr, "deleteLine: invalid index %zu (size %zu)\n", index, b->size);
        return;
    }
    free(b->lines[index]);
// move the pointers after index left by 1
    if (index + 1 < b->size) {
        memmove(&b->lines[index], &b->lines[index+1], (b->size - index - 1) * sizeof(char*));
    }
    b->size--;
}
// print all lines with their indices
void printAllLines(Buffer *b) {
    if (b->size == 0) {
        puts("<buffer is empty>");
        return;
    }
    size_t i;
    for (i = 0; i < b->size; ++i) {
        printf("%zu: %s\n", i, b->lines[i]);
    }
}
// save buffer to a file. Each line ends with a single '\n'. Returns 0 on success.
int saveToFile(Buffer *b, const char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) {
        fprintf(stderr, "Failed to open '%s' for writing: %s\n", filename, strerror(errno));
        return -1;
    }
    size_t i;
    for (i = 0; i < b->size; ++i) {
        if (fprintf(f, "%s\n", b->lines[i]) < 0) {
            fprintf(stderr, "Failed to write to '%s'\n", filename);
            fclose(f);
            return -1;
        }
    }
    fclose(f);
    return 0;
}

// load buffer from file. This frees any existing content and rebuilds the buffer.
// returns 0 on success, -1 on failure.
int loadFromFile(Buffer *b, const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        fprintf(stderr, "Failed to open '%s' for reading: %s\n", filename, strerror(errno));
        return -1;
    }
// clear existing content
    size_t i;
    for (i = 0; i < b->size; ++i) free(b->lines[i]);
    b->size = 0;

// we will reuse the pointer array, but ensure some capacity is present
    if (!b->lines) {
        b->capacity = INITIAL_CAPACITY;
        b->lines = malloc(b->capacity * sizeof(char*));
        if (!b->lines) die_malloc("malloc for lines array in loadFromFile");
    }

    char *line;
    while ((line = readLineFromStream(f)) != NULL) {
        ensureCapacity(b, b->size + 1);
        b->lines[b->size++] = line; // readLineFromStream already allocated exact-sized memory
    }
    fclose(f);
    return 0;
}
// small helper to read a line from stdin into a newly allocated string
char *readLineFromStdin(void) {
    return readLineFromStream(stdin);
}
// simple interactive menu for testing the editor
void printHelp(void) {
    puts("Commands:");
    puts("  a   - append a new line (at end)");
    puts("  i   - insert a new line at index");
    puts("  d   - delete a line at index");
    puts("  p   - print all lines");
    puts("  s   - save buffer to file");
    puts("  l   - load buffer from file (replaces current buffer)");
    puts("  sh  - shrink-to-fit the pointer array");
    puts("  c   - clear buffer (free all lines)");
    puts("  q   - quit (frees memory)");
    puts("  h   - print this help");
}
// FUNCTION main
int main(void) {
    Buffer buf;
    initBuffer(&buf);
    puts("Minimal Line-Based Text Editor (simple interactive demo)");
    puts("Type h for help.");
    char cmd[16];
    while (1) {
        printf("editor> ");
        if (!fgets(cmd, sizeof(cmd), stdin)) break; // EOF/error
        // trim newline
        cmd[strcspn(cmd, "\r\n")] = '\0';

        if (strcmp(cmd, "a") == 0) {
            printf("Enter line: \n");
            char *line = readLineFromStdin();
            if (!line) { puts("No input (EOF)"); continue; }
            insertLine(&buf, buf.size, line);
            free(line); // insertLine makes its own copy
        } else if (strcmp(cmd, "i") == 0) {
            printf("Insert at index: ");
            char idxs[32];
            if (!fgets(idxs, sizeof(idxs), stdin)) continue;
            size_t index = strtoul(idxs, NULL, 10);
            printf("Enter line: \n");
            char *line = readLineFromStdin();
            if (!line) { puts("No input (EOF)"); continue; }
            insertLine(&buf, index, line);
            free(line);
        } else if (strcmp(cmd, "d") == 0) {
            printf("Delete index: ");
            char idxs[32];
            if (!fgets(idxs, sizeof(idxs), stdin)) continue;
            size_t index = strtoul(idxs, NULL, 10);
            deleteLine(&buf, index);
        } else if (strcmp(cmd, "p") == 0) {
            printAllLines(&buf);
        } else if (strcmp(cmd, "s") == 0) {
            printf("Filename to save: ");
            char fname[512];
            if (!fgets(fname, sizeof(fname), stdin)) continue;
            fname[strcspn(fname, "\r\n")] = '\0';
            if (saveToFile(&buf, fname) == 0) printf("Saved to '%s'\n", fname);
        } else if (strcmp(cmd, "l") == 0) {
            printf("Filename to load: ");
            char fname[512];
            if (!fgets(fname, sizeof(fname), stdin)) continue;
            fname[strcspn(fname, "\r\n")] = '\0';
            if (loadFromFile(&buf, fname) == 0) printf("Loaded from '%s'\n", fname);
        } else if (strcmp(cmd, "sh") == 0) {
            shrinkToFit(&buf);
            printf("Shrink-to-fit done. capacity=%zu size=%zu\n", buf.capacity, buf.size);
        } else if (strcmp(cmd, "c") == 0) {
        	size_t i;
            for (i = 0; i < buf.size; ++i) free(buf.lines[i]);
            buf.size = 0;
            printf("Cleared buffer\n");
        } else if (strcmp(cmd, "q") == 0) {
            break;
        } else if (strcmp(cmd, "h") == 0) {
            printHelp();
        } else if (strcmp(cmd, "") == 0) {
            continue; // ignore empty input
        } else {
            printf("Unknown command '%s' - type h for help\n", cmd);
        }
    }
    freeAll(&buf); // freeing the memory allocation
    puts("Goodbye.");
    return 0;
}


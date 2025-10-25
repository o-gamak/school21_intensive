#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
} RECORDS;

int get_records_count_in_file(FILE *pfile) {
    if (!pfile) return 0;
    fseek(pfile, 0, SEEK_END);
    int size = ftell(pfile);
    rewind(pfile);
    return size / sizeof(RECORDS);
}

void read_record_from_file(FILE *pfile, int index, RECORDS *record) {
    if (!pfile || !record) return;
    fseek(pfile, index * sizeof(RECORDS), SEEK_SET);
    fread(record, sizeof(RECORDS), 1, pfile);
}

int parse_date(const char *date_str, int *day, int *month, int *year) {
    if (strlen(date_str) != 10) return 0;
    if (date_str[2] != '.' || date_str[5] != '.') return 0;

    if (sscanf(date_str, "%d.%d.%d", day, month, year) != 3) {
        return 0;
    }

    if (*day < 1 || *day > 31 || *month < 1 || *month > 12 || *year < 0) {
        return 0;
    }

    return 1;
}

void search_by_date(const char *fname, const char *search_date) {
    FILE *fp = fopen(fname, "rb");
    if (!fp) {
        printf("n/a\n");
        return;
    }

    int count = get_records_count_in_file(fp);
    if (count == 0) {
        printf("n/a\n");
        fclose(fp);
        return;
    }

    int search_day, search_month, search_year;
    if (!parse_date(search_date, &search_day, &search_month, &search_year)) {
        printf("n/a\n");
        fclose(fp);
        return;
    }

    RECORDS record;
    int found = 0;

    for (int i = 0; i < count; i++) {
        read_record_from_file(fp, i, &record);

        if (record.day == search_day && record.month == search_month && record.year == search_year) {
            printf("%d\n", record.code);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("n/a\n");
    }

    fclose(fp);
}

int main() {
    char filename[256];
    char search_date[11];

    if (scanf("%255s", filename) != 1) {
        printf("n/a\n");
        return 0;
    }

    if (scanf("%10s", search_date) != 1) {
        printf("n/a\n");
        return 0;
    }

    search_by_date(filename, search_date);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

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

void write_record_to_file(FILE *pfile, int index, RECORDS *record) {
    if (!pfile || !record) return;
    fseek(pfile, index * sizeof(RECORDS), SEEK_SET);
    fwrite(record, sizeof(RECORDS), 1, pfile);
}

void swap_records(FILE *pfile, int i, int j) {
    RECORDS rec1, rec2;
    read_record_from_file(pfile, i, &rec1);
    read_record_from_file(pfile, j, &rec2);
    write_record_to_file(pfile, i, &rec2);
    write_record_to_file(pfile, j, &rec1);
}

int compare_records(const RECORDS *a, const RECORDS *b) {
    if (a->year != b->year) return a->year - b->year;
    if (a->month != b->month) return a->month - b->month;
    if (a->day != b->day) return a->day - b->day;
    if (a->hour != b->hour) return a->hour - b->hour;
    if (a->minute != b->minute) return a->minute - b->minute;
    return a->second - b->second;
}

void output(const char *fname) {
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

    RECORDS record;
    for (int i = 0; i < count; i++) {
        read_record_from_file(fp, i, &record);
        printf("%d %d %d %d %d %d %d %d\n", record.year, record.month, record.day, record.hour, record.minute,
               record.second, record.status, record.code);
    }
    fclose(fp);
}

void sort(const char *fname) {
    FILE *fp = fopen(fname, "rb+");
    if (!fp) {
        printf("n/a\n");
        return;
    }

    int count = get_records_count_in_file(fp);
    if (count <= 1) {
        fclose(fp);
        return;
    }

    RECORDS rec1, rec2;

    for (int i = 0; i < count - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < count - i - 1; j++) {
            read_record_from_file(fp, j, &rec1);
            read_record_from_file(fp, j + 1, &rec2);

            if (compare_records(&rec1, &rec2) > 0) {
                swap_records(fp, j, j + 1);
                swapped = 1;
            }
        }
        if (!swapped) break;
    }

    fclose(fp);
}

void add_record(const char *fname) {
    FILE *check_fp = fopen(fname, "rb");
    if (!check_fp) {
        printf("n/a\n");
        return;
    }
    fclose(check_fp);

    FILE *fp = fopen(fname, "ab");
    if (!fp) {
        printf("n/a\n");
        return;
    }

    RECORDS new_record;
    if (scanf("%d %d %d %d %d %d %d %d", &new_record.year, &new_record.month, &new_record.day,
              &new_record.hour, &new_record.minute, &new_record.second, &new_record.status,
              &new_record.code) != 8) {
        printf("n/a\n");
        fclose(fp);
        return;
    }

    if (new_record.month < 1 || new_record.month > 12 || new_record.day < 1 || new_record.day > 31 ||
        new_record.hour < 0 || new_record.hour > 23 || new_record.minute < 0 || new_record.minute > 59 ||
        new_record.second < 0 || new_record.second > 59 ||
        (new_record.status != 0 && new_record.status != 1)) {
        printf("n/a\n");
        fclose(fp);
        return;
    }

    fwrite(&new_record, sizeof(RECORDS), 1, fp);
    fclose(fp);
}

int main() {
    char filename[256];
    int choice;

    if (scanf("%255s", filename) != 1) {
        printf("n/a\n");
        return 0;
    }

    if (scanf("%d", &choice) != 1) {
        printf("n/a\n");
        return 0;
    }

    switch (choice) {
        case 0:
            output(filename);
            break;
        case 1:
            sort(filename);
            output(filename);
            break;
        case 2:
            add_record(filename);
            sort(filename);
            output(filename);
            break;
        default:
            printf("n/a\n");
            break;
    }

    return 0;
}
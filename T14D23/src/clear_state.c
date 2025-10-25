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

void write_record_to_file(FILE *pfile, int index, RECORDS *record) {
    if (!pfile || !record) return;
    fseek(pfile, index * sizeof(RECORDS), SEEK_SET);
    fwrite(record, sizeof(RECORDS), 1, pfile);
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

int compare_dates(const RECORDS *record, int day, int month, int year) {
    if (record->year != year) return record->year - year;
    if (record->month != month) return record->month - month;
    return record->day - day;
}

void clear_records_in_range(const char *fname, const char *start_date, const char *end_date) {
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

    int start_day, start_month, start_year;
    int end_day, end_month, end_year;

    if (!parse_date(start_date, &start_day, &start_month, &start_year) ||
        !parse_date(end_date, &end_day, &end_month, &end_year)) {
        printf("n/a\n");
        fclose(fp);
        return;
    }

    FILE *temp_fp = tmpfile();
    if (!temp_fp) {
        printf("n/a\n");
        fclose(fp);
        return;
    }

    RECORDS record;
    int kept_count = 0;

    for (int i = 0; i < count; i++) {
        read_record_from_file(fp, i, &record);

        int cmp_start = compare_dates(&record, start_day, start_month, start_year);
        int cmp_end = compare_dates(&record, end_day, end_month, end_year);

        if (cmp_start < 0 || cmp_end > 0) {
            fwrite(&record, sizeof(RECORDS), 1, temp_fp);
            kept_count++;
        }
    }

    fclose(fp);

    if (kept_count == 0) {
        fp = fopen(fname, "wb");
        if (fp) fclose(fp);
        printf("n/a\n");
        fclose(temp_fp);
        return;
    }

    fp = fopen(fname, "wb");
    if (!fp) {
        printf("n/a\n");
        fclose(temp_fp);
        return;
    }

    rewind(temp_fp);
    for (int i = 0; i < kept_count; i++) {
        fread(&record, sizeof(RECORDS), 1, temp_fp);
        fwrite(&record, sizeof(RECORDS), 1, fp);

        printf("%d %d %d %d %d %d %d %d\n", record.year, record.month, record.day, record.hour, record.minute,
               record.second, record.status, record.code);
    }

    fclose(fp);
    fclose(temp_fp);
}

int main() {
    char filename[256];
    char start_date[11], end_date[11];

    if (scanf("%255s", filename) != 1) {
        printf("n/a\n");
        return 0;
    }

    if (scanf("%10s %10s", start_date, end_date) != 2) {
        printf("n/a\n");
        return 0;
    }

    clear_records_in_range(filename, start_date, end_date);

    return 0;
}
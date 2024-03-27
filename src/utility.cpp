#include <iostream>
#include <archive.h>
#include <archive_entry.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "../include/utility.h"

Utility::Utility() {}
void Utility::listArchiveFiles(const char* fileName) {
    struct archive* a;
    struct archive_entry* entry;
    int r;
    a = archive_read_new();
    archive_read_support_filter_all(a);
    archive_read_support_format_all(a);
    r = archive_read_open_filename(a, fileName, 10240);
    if (r != ARCHIVE_OK) {
        std::cerr << "Failed to open archive.\n";
    }

    while (archive_read_next_header(a, &entry) == ARCHIVE_OK) {
        std::cout << archive_entry_pathname(entry) << std::endl;
        archive_read_data_skip(a);
    }

    archive_read_close(a);
    archive_read_free(a);
}
void Utility::createArchive(const char* outname,const char** fileNames) {
    struct archive *a;
  struct archive_entry *entry;
  struct stat st;
  char buff[8192];
  int len;
  int fd;

  a = archive_write_new();
  archive_write_add_filter_gzip(a);
  archive_write_set_format_pax_restricted(a); // Note 1
  archive_write_open_filename(a, outname);
  while (*fileNames) {
    stat(*fileNames, &st);
    entry = archive_entry_new(); // Note 2
    archive_entry_set_pathname(entry, *fileNames);
    archive_entry_set_size(entry, st.st_size); // Note 3
    archive_entry_set_filetype(entry, AE_IFREG);
    archive_entry_set_perm(entry, 0644);
    archive_write_header(a, entry);
    fd = open(*fileNames, O_RDONLY);
    len = read(fd, buff, sizeof(buff));
    while ( len > 0 ) {
        archive_write_data(a, buff, len);
        len = read(fd, buff, sizeof(buff));
    }
    close(fd);
    archive_entry_free(entry);
    fileNames++;
  }
  archive_write_close(a);
  archive_write_free(a);
}
Utility::~Utility() {}
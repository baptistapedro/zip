#include <stdio.h>
#include <string.h>
#include "zip.h"

int main(int argc, char **argv) {
struct zip_t *zip = zip_open("foo.zip", ZIP_DEFAULT_COMPRESSION_LEVEL, 'w');
{
    zip_entry_open(zip, "foo-1.txt");
    {
        const char *buf = "Some data here...\0";
        zip_entry_write(zip, buf, strlen(buf));
    }
    zip_entry_close(zip);

    zip_entry_open(zip, "foo-2.txt");
    {
        // merge 3 files into one entry and compress them on-the-fly.
        zip_entry_fwrite(zip, argv[1]);

    }
    zip_entry_close(zip);
}
zip_close(zip);
return 0;
}

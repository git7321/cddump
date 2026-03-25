/*++

Copyright (c) 1995  Microsoft Corporation

Module Name:

    read.c

Abstract:

    dump cd tracks/sectors to wav files

Environment:

    User mode only

Revision History:

    05-26-98 : Created

--*/

#include "common.h"

#define LARGEST_SECTORS_PER_READ 27

ULONG32
CddumpDumpLba(
    HANDLE CdromHandle,
    HANDLE OutHandle,
    ULONG  StartAddress,
    ULONG  EndAddress
    )
{
    RAW_READ_INFO info;
    PUCHAR sample;
    ULONG bytesReturned;
    ULONG currentLba;
    ULONG temp;
    ULONG sectorsPerRead;

    sample = NULL;
    currentLba = StartAddress;
    sectorsPerRead = LARGEST_SECTORS_PER_READ;

    TRY {

        sample = malloc(RAW_SECTOR_SIZE*LARGEST_SECTORS_PER_READ);
        if (sample == NULL) {
            printf("DumpLba => No memory for sample\n");
            LEAVE;
        }

        while (sectorsPerRead != 0) {

            while (currentLba + sectorsPerRead <= EndAddress) {

                info.DiskOffset.QuadPart = (ULONGLONG)(currentLba*(ULONGLONG)2048);
                info.SectorCount         = sectorsPerRead;
                info.TrackMode           = CDDA;

                if(!DeviceIoControl(CdromHandle,
                                    IOCTL_CDROM_RAW_READ,
                                    &info,
                                    sizeof(RAW_READ_INFO),
                                    sample,
                                    RAW_SECTOR_SIZE * sectorsPerRead,
                                    &bytesReturned,
                                    FALSE
                                    )
                   ) {
                    DWORD error = GetLastError();

                    if (error == ERROR_INVALID_PARAMETER) {
                        printf("ERROR_INVALID_PARAMTER for read size %x, "
                               "trying smaller transfer\n", sectorsPerRead);
                        break;
                    } else {
                        printf("Error %d sending IOCTL_CDROM_RAW_READ for sector %d\n",
                               GetLastError(), currentLba);
                        LEAVE;
                    }
                }

                if (bytesReturned != RAW_SECTOR_SIZE * sectorsPerRead) {

                    printf("Only returned %d of %d bytes for read %d\n",
                           bytesReturned,
                           RAW_SECTOR_SIZE * sectorsPerRead,
                           currentLba
                           );
                    LEAVE;
                }

                if (!WriteFile(OutHandle,
                               sample,
                               RAW_SECTOR_SIZE * sectorsPerRead,
                               &temp,
                               NULL)) {

                    printf("Unable to write data for read %d\n", currentLba);
                    LEAVE;
                }

                currentLba += sectorsPerRead;

            }

            sectorsPerRead /= 2;

        }

    } FINALLY {

        if (sample) {
            free(sample);
        }

    }

    return 0;
}

PCDROM_TOC
CddumpGetToc(
    HANDLE device
    )
{
    PCDROM_TOC  toc;
    ULONG bytesReturned;
    ULONG errorValue;

    toc = (PCDROM_TOC)malloc( sizeof(CDROM_TOC) );
    if ( toc == NULL ) {
        printf( "Insufficient memory\n" );
        return NULL;
    }

    if( !DeviceIoControl( device,
                          IOCTL_CDROM_READ_TOC,
                          NULL,
                          0,
                          toc,
                          sizeof(CDROM_TOC),
                          &bytesReturned,
                          FALSE
                          )
        ) {
        errorValue = GetLastError();
        printf( "Error %d sending IOCTL_CDROM_READ_TOC\n", errorValue );
        free( toc );
        return NULL;
    }
    return toc;
}

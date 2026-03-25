#ifndef __CDDUMP_COMMON_H__
#define __CDDUMP_COMMON_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <windows.h>
#include <devioctl.h>
#include <ntddcdrm.h>

#ifdef __cplusplus
extern "C" {
#endif

#define STATUS_SUCCESS     ( 0 )
#define RAW_SECTOR_SIZE    ( 2352 )
#define SAMPLES_PER_SECTOR ( RAW_SECTOR_SIZE / sizeof(SAMPLE) )
#define REDBOOK_INACCURACY ( 75 )
#define TRY
#define LEAVE              goto __label;
#define FINALLY            __label:

#define LBA_TO_MSF(Lba,Minutes,Seconds,Frames)   \
{                                                \
    (Minutes) = (UCHAR)(Lba  / (60 * 75));       \
    (Seconds) = (UCHAR)((Lba % (60 * 75)) / 75); \
    (Frames)  = (UCHAR)((Lba % (60 * 75)) % 75); \
}

#define MSF_TO_LBA(Minutes,Seconds,Frames) \
    (ULONG)((60 * 75 * (Minutes) ) + (75 * (Seconds)) + ((Frames) - 150))

typedef struct _SAMPLE {
    union {
        UCHAR  Data[4];
        struct {
            SHORT Left;
            SHORT Right;
        };
    };
    ULONG32 AsUlong32;
} SAMPLE, *PSAMPLE;

PCDROM_TOC
CddumpGetToc(
    HANDLE device
    );

ULONG
CDDB_ID(
    PCDROM_TOC toc
    );

ULONG32
CddumpDumpLba(
    HANDLE CdromHandle,
    HANDLE OutHandle,
    ULONG  StartAddress,
    ULONG  EndAddress
    );

ULONG32
DumpWavHeader(
    HANDLE  OutFile,
    ULONG32 Samples,
    ULONG32 SamplesPerSecond,
    USHORT  Channels,
    USHORT  BitsPerSample
    );

VOID
ReadWavHeader(
    HANDLE InFile
    );

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __CDDUMP_COMMON_H__

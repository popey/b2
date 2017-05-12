#ifndef HEADER_B9662BEB223148FC8148B4BF707D4B3D
#define HEADER_B9662BEB223148FC8148B4BF707D4B3D

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// Global constants/defines/etc.

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#if BUILD_TYPE_Debug

#define BBCMICRO_TRACE 1

#elif BUILD_TYPE_RelWithDebInfo

#define BBCMICRO_TRACE 1

#elif BUILD_TYPE_Final

#define BBCMICRO_TRACE 0

#else
#error unexpected build type
#endif

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// Number of disc drives.
#define NUM_DRIVES (2)

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#define TRACK_VIDEO_LATENCY 0

// if true, blend last frame's values with current
#define BLEND 0

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#define BBCMICRO_ENABLE_DISC_DRIVE_SOUND 1

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#define BBCMICRO_TURBO_DISC 1

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

/* If defined, produce finer-resolution teletext output
 * Finer-resolution means more pixels - rather than increase the
 * output pixel clock, this changes the video output data format. */
#define BBCMICRO_FINER_TELETEXT 1

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// if defined, enable 1770 write functionality
#define WD1770_ENABLE_WRITE 1

#if BUILD_TYPE_Final

// The 1770 logging stuff is always stripped out in this mode.

#else

// if true, dump sector contents on completion of the corresponding
// type of command
#define WD1770_DUMP_WRITTEN_SECTOR 0
#define WD1770_DUMP_READ_SECTOR 0

// if true, log each byte read to/written from the data register
// during the corresponding type of command
#define WD1770_VERBOSE_READ_SECTOR 0
#define WD1770_VERBOSE_WRITE_SECTOR 0
#define WD1770_VERBOSE_WRITES 0

// if true, log every state change
#define WD1770_VERBOSE_STATE_CHANGES 0

#endif

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#endif

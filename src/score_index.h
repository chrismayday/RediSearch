#ifndef __SCORE_INDEX_H__
#define __SCORE_INDEX_H__
#include "buffer.h"
#include "types.h"
#include "util/heap.h"

#define MAX_SCOREINDEX_SIZE 20

#pragma pack(4)
typedef struct {
    t_offset offset;
    float score;
    t_docId docId;
} ScoreIndexEntry;
#pragma pack()

static int ScoreEntry_cmp(const void *e1,  const void *e2, const void *udata);

 typedef struct {
    u_short numEntries;
    u_short lowestIndex;
    float lowestScore;
 } ScoreIndexHeader;

typedef struct {
    ScoreIndexEntry *entries;
    ScoreIndexHeader header;
    u_short offset;
    Buffer *buf;
} ScoreIndex;

typedef struct {
    BufferWriter bw;
    ScoreIndexHeader header;
} ScoreIndexWriter;

ScoreIndex *NewScoreIndex(Buffer *b);
ScoreIndexEntry *ScoreIndex_Next(ScoreIndex *si);
void ScoreIndex_Free(ScoreIndex *si);
ScoreIndexWriter NewScoreIndexWriter(BufferWriter bw);
static inline int ScoreEntry_cmp(const void *e1,  const void *e2, const void *udata); 
int ScoreIndexWriter_AddEntry(ScoreIndexWriter *w, float score, t_offset offset, t_docId docId) ;

#endif
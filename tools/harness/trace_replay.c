/*
 * Native hot paths for fast deterministic-trace replay (Frida CModule, IA-32).
 *
 * The game sees only recorded clock values and recorded message-pump results.
 * This file reproduces human_message_replay.js, human_clock_replay.js, and
 * human_alloc_fill.js without a JavaScript transition per call. Rare paths
 * (owned child windows, new RNG sites, input bookkeeping, failures) call the
 * js_* callbacks in trace_replay.js.
 *
 * Message records are 80 bytes, format aoe-message-pump-v7-le. Field n is the
 * little-endian u32 at offset 4 * n; see human_message_observe.js.
 */
#include <gum/guminterceptor.h>

typedef unsigned int u32;
typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned long long u64;
#define API __attribute__((stdcall))

extern int API user_invalidate (void * hwnd, void * rect, int erase);
extern u32 API current_thread (void);
extern void js_fail (u32 code);
extern void * js_window (u32 id);
extern int js_owned (void * hwnd);
extern u32 js_site (u32 kind, const char * file, s32 line);
extern void js_flush (void);
extern void js_bind (void);
extern void js_removed (u32 message, u32 value, u32 parameter, void * hwnd);
extern int js_dispatch_input (u32 * msg);
extern void js_dispatched (void);
extern void js_dump_state (u8 * world);

/*
 * CModule images are mapped read-execute, so all mutable state lives in memory
 * that trace_replay.js allocates. S holds scalars at the indices below; the JS
 * side uses the same indices (STATE in trace_replay.js).
 */
extern u32 S[];
extern u8 KEYS[];
typedef struct { const char * file; s32 line; u32 kind; u32 id; } Site;
extern Site SITES[];
typedef struct { u32 * msg; u32 thread; } Active;
extern Active ACTIVE[];

#define READY S[0]
#define TRACE_THREAD S[1]
#define GAME_THREAD S[2]
#define STOPPED S[3]
#define STOP_REQUESTED S[4]
#define STOP_TRACE_COMPLETE S[5]
#define GAME_WINDOW ((void *) S[6])
#define TRACE ((u8 *) S[7])
#define TRACE_RECORDS S[8]
#define TRACE_INDEX S[9]
#define CLOCK_RUNS ((u32 *) S[10])
#define CLOCK_RUN_COUNT S[11]
#define CLOCK_RUN S[12]
#define CLOCK_RUN_USED S[13]
#define CLOCK_CALLS S[14]
#define TICKS S[15]
#define UPDATES S[16]
#define INPUT S[17]
#define TURN S[18]
#define BOUND S[19]
#define DURATION_MS ((s32) S[20])
#define FAIL_CODE S[21]
#define FAIL_INDEX S[22]
#define CURSOR_X S[23]
#define CURSOR_Y S[24]
#define OBSERVE S[25]
#define RNG_BUF ((u32 *) S[26])
#define RNG_CAP S[27]
#define RNG_USED S[28]
#define RNG_TOTAL S[29]
#define UPD_BUF ((u32 *) S[30])
#define UPD_CAP S[31]
#define UPD_USED S[32]
#define WORLD_TIME S[33]
#define WORLD_OBJECTS S[34]
#define CAMERA_PLAYER S[35]
#define CAMERA_SEEN S[36]
#define CAMERA_CHANGES S[37]
#define CAMERA_X (*(float *) &S[38])
#define CAMERA_Y (*(float *) &S[39])
#define ALLOC_BLOCKS S[40]
#define ALLOC_BYTES_LO S[41]
#define ALLOC_BYTES_HI S[42]
#define NATIVE_PEEK ((int (API *) (void *, void *, u32, u32, u32)) S[43])
#define NATIVE_GET ((int (API *) (void *, void *, u32, u32)) S[44])
#define ACTIVE_COUNT S[45]
#define DUMP_AT S[46] /* Completed-update count to dump object state at, or 0. */
/* Optional clock-site log: [updates, line, file hash] per clock read in an update window. */
#define CLOCK_LOG ((u32 *) S[47])
#define CLOCK_LOG_CAP S[48]
#define CLOCK_LOG_USED S[49]
#define CLOCK_LOG_FIRST S[50]
#define CLOCK_LOG_LAST S[51]
#define SITE_SLOTS 4096
#define ACTIVE_SLOTS 64

static u32
field (u32 index)
{
  return ((u32 *) (TRACE + TRACE_INDEX * 80))[index];
}

static void
fail (u32 code)
{
  if (FAIL_CODE == 0)
  {
    FAIL_CODE = code;
    FAIL_INDEX = TRACE_INDEX;
  }
  js_fail (code); /* Parks the thread after the report is sent. */
}

static int
is_input (u32 message)
{
  return (message >= 0x100 && message <= 0x107) || (message >= 0x200 && message <= 0x20e);
}

static void
check_state (void)
{
  if (field (16) != UPDATES)
    fail (2);
  else if (field (17) != INPUT)
    fail (3);
}

static void *
window_for (u32 id)
{
  if (id == 0)
    return 0;
  if (id == 1)
    return GAME_WINDOW;
  return js_window (id);
}

static void
consume_enter (u32 api, u32 * msg, u32 min, u32 max, u32 flags)
{
  if (field (0) != (api | 0x80000000u))
  {
    fail (1);
    return;
  }
  check_state ();
  if (api < 5)
  {
    if (field (5) != min || field (6) != max || field (7) != flags)
      fail (4);
  }
  else if (msg != 0 && (msg[1] != field (9) || msg[2] != field (10) || msg[3] != field (11)))
    fail (5);
  TRACE_INDEX++;
}

static u32
consume (u32 api, u32 * msg)
{
  u32 result;
  if (TRACE_INDEX >= TRACE_RECORDS)
  {
    fail (10);
    return 0;
  }
  if (field (0) != api)
  {
    fail (1);
    return 0;
  }
  check_state ();
  result = field (3);
  if (msg != 0 && result != 0xffffffffu && (api >= 5 || result != 0))
  {
    u32 message = field (9), value = field (10), parameter = field (11);
    void * hwnd = (void *) msg[0];
    int removed;
    if (api < 5)
    {
      hwnd = window_for (field (8));
      msg[0] = (u32) hwnd;
      msg[1] = message;
      msg[2] = value;
      msg[3] = parameter;
      msg[4] = field (12);
      msg[5] = field (13);
      msg[6] = field (14);
    }
    else if (msg[1] != message || msg[2] != value || msg[3] != parameter)
      fail (6);
    removed = api == 1 || (api == 3 && (field (7) & 1));
    if (removed && is_input (message))
      js_removed (message, value, parameter, hwnd);
  }
  TRACE_INDEX++;
  return result;
}

static void
finish_trace (void)
{
  if (!STOPPED && !STOP_REQUESTED)
  {
    STOP_REQUESTED = 1;
    STOP_TRACE_COMPLETE = 1;
    user_invalidate (GAME_WINDOW, 0, 0);
  }
}

static int
replaying (void)
{
  return READY && TRACE_THREAD && current_thread () == TRACE_THREAD;
}

int API
replay_peek (u32 * msg, void * hwnd, u32 min, u32 max, u32 flags)
{
  if (!replaying ())
    return NATIVE_PEEK (msg, hwnd, min, max, flags);
  if (TRACE_INDEX >= TRACE_RECORDS)
  {
    finish_trace ();
    return NATIVE_PEEK (msg, hwnd, min, max, flags);
  }
  consume_enter (3, msg, min, max, flags);
  if (field (5) != min || field (6) != max || field (7) != flags)
    fail (8);
  return (int) consume (3, msg);
}

int API
replay_get (u32 * msg, void * hwnd, u32 min, u32 max)
{
  if (!replaying ())
    return NATIVE_GET (msg, hwnd, min, max);
  if (TRACE_INDEX >= TRACE_RECORDS)
  {
    finish_trace ();
    return NATIVE_GET (msg, hwnd, min, max);
  }
  consume_enter (1, msg, min, max, 0);
  if (field (5) != min || field (6) != max)
    fail (8);
  return (int) consume (1, msg);
}

static int
owned (void * hwnd)
{
  return hwnd == 0 || hwnd == GAME_WINDOW || js_owned (hwnd);
}

/* The recording contains WM_CHAR, so replay translation generates nothing. */
int API
replay_translate (u32 * msg)
{
  if (replaying () && TRACE_INDEX < TRACE_RECORDS && owned ((void *) msg[0]))
  {
    consume_enter (5, msg, 0, 0, 0);
    consume (5, msg);
  }
  return 0;
}

typedef struct { u32 * msg; u32 thread; int outer; int delivered; int replay; } DispatchState;

void
dispatch_enter (GumInvocationContext * ic)
{
  DispatchState * s = gum_invocation_context_get_listener_invocation_data (ic, sizeof (DispatchState));
  u32 * msg = gum_invocation_context_get_nth_argument (ic, 0);
  u32 thread = gum_invocation_context_get_thread_id (ic);
  int i;
  s->msg = msg;
  s->thread = thread;
  s->delivered = 0;
  s->replay = 0;
  s->outer = 1;
  for (i = 0; i < ACTIVE_COUNT; i++)
    if (ACTIVE[i].msg == msg && ACTIVE[i].thread == thread)
      s->outer = 0;
  if (s->outer)
  {
    if (ACTIVE_COUNT < ACTIVE_SLOTS)
    {
      ACTIVE[ACTIVE_COUNT].msg = msg;
      ACTIVE[ACTIVE_COUNT].thread = thread;
      ACTIVE_COUNT++;
    }
    /* The recorder takes F10 as its stop key and blanks the message before the game sees it. */
    if (GAME_WINDOW != 0 && !STOPPED && (msg[1] == 0x100 || msg[1] == 0x104) && msg[2] == 0x79)
      msg[1] = 0;
    if (GAME_WINDOW != 0 && !STOPPED && is_input (msg[1]))
      s->delivered = js_dispatch_input (msg);
  }
  if (READY && TRACE_THREAD && thread == TRACE_THREAD && TRACE_INDEX < TRACE_RECORDS && owned ((void *) msg[0]))
  {
    s->replay = 1;
    consume_enter (6, msg, 0, 0, 0);
  }
}

void
dispatch_leave (GumInvocationContext * ic)
{
  DispatchState * s = gum_invocation_context_get_listener_invocation_data (ic, sizeof (DispatchState));
  int i;
  if (s->replay)
    consume (6, s->msg);
  if (s->outer)
  {
    for (i = ACTIVE_COUNT - 1; i >= 0; i--)
      if (ACTIVE[i].msg == s->msg && ACTIVE[i].thread == s->thread)
      {
        ACTIVE[i] = ACTIVE[ACTIVE_COUNT - 1];
        ACTIVE_COUNT--;
        break;
      }
    if (s->delivered && !STOPPED)
      js_dispatched ();
  }
}

void
wndproc_enter (GumInvocationContext * ic)
{
  if (GAME_WINDOW != 0 && gum_invocation_context_get_nth_argument (ic, 0) == GAME_WINDOW)
    TRACE_THREAD = gum_invocation_context_get_thread_id (ic);
}

void
idle_leave (GumInvocationContext * ic)
{
  if (GAME_WINDOW == 0 || STOPPED || gum_invocation_context_get_thread_id (ic) != GAME_THREAD)
    return;
  TURN++;
  if (!BOUND)
  {
    BOUND = 1;
    js_bind ();
  }
  if (STOP_REQUESTED || (s32) (TICKS - 1000) >= DURATION_MS)
    user_invalidate (GAME_WINDOW, 0, 0);
}

u32
replay_clock (void * file, s32 line)
{
  u32 value;
  if (CLOCK_RUN >= CLOCK_RUN_COUNT)
  {
    fail (7);
    return TICKS;
  }
  value = CLOCK_RUNS[CLOCK_RUN * 2];
  if (++CLOCK_RUN_USED == CLOCK_RUNS[CLOCK_RUN * 2 + 1])
  {
    CLOCK_RUN++;
    CLOCK_RUN_USED = 0;
  }
  CLOCK_CALLS++;
  TICKS = value;
  if (CLOCK_LOG_CAP != 0 && UPDATES >= CLOCK_LOG_FIRST && UPDATES <= CLOCK_LOG_LAST && CLOCK_LOG_USED < CLOCK_LOG_CAP)
  {
    const u8 * c = (const u8 *) file;
    u32 * row = CLOCK_LOG + CLOCK_LOG_USED * 3;
    u32 hash = 2166136261u;
    while (c != 0 && *c != 0)
    {
      u8 ch = *c++;
      hash = (hash ^ (ch >= 'A' && ch <= 'Z' ? ch + 32 : ch)) * 16777619u;
    }
    row[0] = UPDATES;
    row[1] = (u32) line;
    row[2] = hash;
    CLOCK_LOG_USED++;
  }
  return value;
}


static void
rng_record (u32 kind, const char * file, s32 line, u32 value)
{
  u32 slot, id;
  RNG_TOTAL++;
  if (!OBSERVE)
    return;
  slot = ((u32) file * 31u + (u32) line * 7u + kind) & (SITE_SLOTS - 1);
  while (SITES[slot].file != 0 && !(SITES[slot].file == file && SITES[slot].line == line && SITES[slot].kind == kind))
    slot = (slot + 1) & (SITE_SLOTS - 1);
  if (SITES[slot].file == 0)
  {
    /* js_site flushes pending records before it announces the new site. */
    id = js_site (kind, file, line);
    SITES[slot].file = file;
    SITES[slot].line = line;
    SITES[slot].kind = kind;
    SITES[slot].id = id;
  }
  id = SITES[slot].id;
  if (RNG_USED == RNG_CAP)
    js_flush ();
  RNG_BUF[RNG_USED * 2] = id;
  RNG_BUF[RNG_USED * 2 + 1] = value;
  RNG_USED++;
}

typedef struct { const char * file; s32 line; } RandState;

void
rand_enter (GumInvocationContext * ic)
{
  RandState * s = gum_invocation_context_get_listener_invocation_data (ic, sizeof (RandState));
  s->file = gum_invocation_context_get_nth_argument (ic, 0);
  s->line = (s32) gum_invocation_context_get_nth_argument (ic, 1);
}

void
rand_leave (GumInvocationContext * ic)
{
  RandState * s = gum_invocation_context_get_listener_invocation_data (ic, sizeof (RandState));
  rng_record (1, s->file, s->line, (u32) gum_invocation_context_get_return_value (ic));
}

void
srand_enter (GumInvocationContext * ic)
{
  rng_record (0, gum_invocation_context_get_nth_argument (ic, 0),
              (s32) gum_invocation_context_get_nth_argument (ic, 1),
              (u32) gum_invocation_context_get_nth_argument (ic, 2));
}

void
new_enter (GumInvocationContext * ic)
{
  *(u32 *) gum_invocation_context_get_listener_invocation_data (ic, sizeof (u32)) =
      (u32) gum_invocation_context_get_nth_argument (ic, 0);
}

void
new_leave (GumInvocationContext * ic)
{
  u32 size = *(u32 *) gum_invocation_context_get_listener_invocation_data (ic, sizeof (u32));
  u8 * block = gum_invocation_context_get_return_value (ic);
  u32 i;
  if (block == 0 || size == 0 || size > 0x4000000)
    return;
  for (i = 0; i < size; i++)
    block[i] = 0;
  ALLOC_BLOCKS++;
  {
    u32 before = ALLOC_BYTES_LO;
    ALLOC_BYTES_LO += size;
    if (ALLOC_BYTES_LO < before)
      ALLOC_BYTES_HI++;
  }
}

/*
 * FNV-1a over each live object's id, master id, owner id, hp, position, and
 * object state. Offsets match human_observe.js objectValue(). This digest only
 * compares executables; it is not part of the recorded oracle.
 */
static u32
state_hash (u8 * world)
{
  u8 ** objects = *(u8 ***) (world + 136);
  s32 count = *(s32 *) (world + 144);
  u32 hash = 2166136261u;
  s32 i;
  if (objects == 0)
    return 0;
  for (i = 0; i < count; i++)
  {
    u8 * object = objects[i];
    u32 words[8];
    u8 * master;
    u8 * owner;
    u32 j;
    if (object == 0)
      continue;
    master = *(u8 **) (object + 8);
    owner = *(u8 **) (object + 12);
    words[0] = *(u32 *) (object + 4);
    words[1] = master != 0 ? (u32) *(s16 *) (master + 16) : 0xffffffffu;
    words[2] = owner != 0 ? (u32) *(s16 *) (owner + 74) : 0xffffffffu;
    words[3] = *(u32 *) (object + 48);
    words[4] = *(u32 *) (object + 56);
    words[5] = *(u32 *) (object + 60);
    words[6] = *(u32 *) (object + 64);
    words[7] = *(u8 *) (object + 72);
    for (j = 0; j < 32; j++)
    {
      hash ^= ((u8 *) words)[j];
      hash *= 16777619u;
    }
  }
  return hash;
}

void
world_enter (GumInvocationContext * ic)
{
  *(u32 *) gum_invocation_context_get_listener_invocation_data (ic, sizeof (u32)) = ic->cpu_context->ecx;
}

void
world_leave (GumInvocationContext * ic)
{
  u8 * world = (u8 *) *(u32 *) gum_invocation_context_get_listener_invocation_data (ic, sizeof (u32));
  u32 * row;
  UPDATES++;
  WORLD_TIME = *(u32 *) (world + 4);
  WORLD_OBJECTS = *(u32 *) (world + 140);
  if (DUMP_AT != 0 && UPDATES == DUMP_AT)
    js_dump_state (world);
  if (!OBSERVE)
    return;
  if (UPD_USED == UPD_CAP)
    js_flush ();
  row = UPD_BUF + UPD_USED * 5;
  row[0] = RNG_TOTAL; /* Every RNG call is observed when OBSERVE is set. */
  row[1] = UPDATES;
  row[2] = INPUT;
  row[3] = WORLD_TIME;
  row[4] = state_hash (world);
  UPD_USED++;
}

void
camera_enter (GumInvocationContext * ic)
{
  *(u32 *) gum_invocation_context_get_listener_invocation_data (ic, sizeof (u32)) = ic->cpu_context->ecx;
}

void
camera_leave (GumInvocationContext * ic)
{
  u8 * player = (u8 *) *(u32 *) gum_invocation_context_get_listener_invocation_data (ic, sizeof (u32));
  s32 id = *(s16 *) (player + 74);
  float x = *(float *) (player + 276), y = *(float *) (player + 280);
  if (!CAMERA_SEEN || id != CAMERA_PLAYER || x != CAMERA_X || y != CAMERA_Y)
  {
    CAMERA_SEEN = 1;
    CAMERA_PLAYER = id;
    CAMERA_X = x;
    CAMERA_Y = y;
    CAMERA_CHANGES++;
  }
}

s16 API
key_state (s32 key)
{
  return key >= 0 && key < 256 && KEYS[key] ? (s16) 0x8000 : 0;
}

/* Arrow-key scrolling reads GetKeyboardState. SetKeyboardState does not reach it in a hidden replay. */
int API
keyboard_state (u8 * state)
{
  s32 key;
  for (key = 0; key < 256; key++)
    state[key] = KEYS[key] ? 0x80 : 0;
  return 1;
}

int API
cursor_pos (s32 * point)
{
  point[0] = (s32) CURSOR_X;
  point[1] = (s32) CURSOR_Y;
  return 1;
}

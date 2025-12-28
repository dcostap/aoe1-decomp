// AI CONTEXT: COMMON TYPES
#pragma once

enum __unnamed {
    InvalidGroup = 0,
    MaxGroups = 5,
    MaxTargetTypes = 5,
    MaxUnitTypes = 6,
    MaxPhases = 10,
    MaxUnits = 50,
    MaxNameLength = 64,
};
enum __unnamed {
    MaxNameLength = 64,
    MaximumNumberPlays = 2000,
};
enum __unnamed {
    MaxUnitTypes = 6,
    InvalidGroup = 255,
};
enum __unnamed {
    MaxTriggers = 3,
    MaxCommands = 5,
};
enum __unnamed {
    InvalidCommand = 0,
    MoveCommand = 1,
    AttackCommand = 2,
    AttackSavedTargetCommand = 3,
    RetreatCommand = 4,
    HealCommand = 5,
    ResetHitPointsCommand = 6,
    ResetAliveCountCommand = 7,
    WaitCommand = 8,
};
enum __unnamed {
    InvalidTrigger = 0,
    GatherTrigger = 1,
    DeathTrigger = 2,
    HealthLostTrigger = 3,
    DamageToGroupTrigger = 4,
    DamageToAnyGroupTrigger = 5,
    Level1EnemySightedTrigger = 6,
    Level2EnemySightedTrigger = 7,
    DeathOfGroupTrigger = 8,
    HealOfGroupTrigger = 9,
    ImmediateTrigger = 10,
    TimeTrigger = 11,
};
enum __unnamed {
    FirstPhase = 253,
    EndPhase = 254,
    InvalidPhase = 255,
};
enum __unnamed {
    MaxUnitTypes = 50,
};
enum __unnamed {
    Ally = 0,
    Disliked = 0,
    MinimumStanceValue = 0,
    Ambivalent = 1,
    Neutral = 1,
    Liked = 2,
    Enemy = 3,
    AmbivalentStanceValue = 49,
    MaximumStanceValue = 100,
};
enum __unnamed {
    Aggressive = 0,
    MinimumStateValue = 0,
    Compassionate = 1,
    Defensive = 2,
    Friendly = 3,
    DefaultState = 4,
    Passive = 4,
    Vengeful = 5,
    NumberStates = 6,
    InitialStateValue = 49,
    MaximumStateValue = 100,
};
enum __unnamed {
    CollisionWithTarget = 0,
    Passable = 1,
    MaximumFacets = 8,
    Impassable = 254,
    MaxMapSize = 255,
    UnusedFacet = 255,
    MaxPathingIterations = 20000,
};
enum __unnamed {
    UnderRange = 0,
    InRange = 1,
    OutOfRange = 2,
};
enum __unnamed {
    Stop = 0,
    KeepGoing = 1,
    GoalFound = 2,
};
enum __unnamed {
    DefaultPathingAttemptCapValue = 5,
    DefaultPathingDelayCapValue = 10,
    MaximumChatMessageSize = 1024,
};
enum __unnamed {
    MaximumZones = 255,
};
enum __unnamed {
    MaxResources = 8,
};
enum __unnamed {
    NONE = 0,
    DESTROY = 1,
    CREATE = 2,
    BRING = 3,
    ATTRIBUTE = 4,
    CAPTURE = 5,
    OTHER_ATTRIBUTE = 6,
    TECH = 7,
};
enum __unnamed {
    ErrorNone = 0,
    ErrorOther = 1,
    Error256 = 2,
};
enum __unnamed {
    BackPosTopLeft = 0,
    BackPosCentered = 1,
    BackPosTiled = 2,
};
enum __unnamed {
    NoClock = 0,
    RealClock = 1,
    GameClock = 2,
    TimeLimitClock = 3,
    WonderClock = 4,
    ArtifactClock = 5,
    RuinClock = 6,
};
enum __unnamed {
    Stone = 0,
    Tool = 1,
    Bronze = 2,
    Iron = 3,
    All = 4,
};
enum __unnamed {
    NoAction = 0,
    Idle = 1,
    Attack = 2,
    Retreat = 3,
    Defend = 4,
    Follow = 5,
    Patrol = 6,
    Exterminate = 7,
    Explore = 8,
    Gather = 9,
    Fish = 10,
    Trade = 11,
    Transport = 12,
    Waiting = 13,
    TightGather = 14,
    EnteringTransport = 15,
    BeingTransported = 16,
    MovingToAttack = 17,
    IntelligentAttack = 18,
    Artifacting = 19,
    AttackIdleRoundup = 20,
    AttackWithMove = 21,
    Stop = 22,
    MaximumUnits = 40,
};
enum __unnamed {
    HandUnit = 0,
    RangedUnit = 1,
    CavalryUnit = 2,
    LegionUnit = 3,
    PriestUnit = 4,
    SiegeUnit = 5,
};
enum __unnamed {
    Explored = 0,
    LOSLayer = 0,
    ObjectLayer = 1,
    Unexploreable = 1,
    SoldierUnexplored = 2,
    TerrainLayer = 2,
    NumberCityLayers = 3,
    MaxMapHeight = 254,
    MaxMapWidth = 254,
    Unexplored = 255,
};
enum __unnamed {
    LookAtMap = 0,
    GiveResource = 1,
    Attack = 2,
    Help = 3,
    MoveTo = 4,
    Object = 5,
    SetRelation = 6,
    SetDiplomacyTributeAmount = 7,
};
enum __unnamed {
    GAIAHealDistance = 2,
    ContinuousHealDistance = 4,
};
enum __unnamed {
    NumberUpdateAreas = 22,
    MaximumNumberUnits = 50,
};
enum __unnamed {
    MaxWaypointQueueSize = 8,
};
enum __unnamed {
    ExecuteOnVCSet = -2,
    AlwaysExecute = -1,
};
enum __unnamed {
    skipws = 1,
    left = 2,
    right = 4,
    internal = 8,
    dec = 16,
    oct = 32,
    hex = 64,
    showbase = 128,
    showpoint = 256,
    uppercase = 512,
    showpos = 1024,
    scientific = 2048,
    fixed = 4096,
    unitbuf = 8192,
    stdio = 16384,
};
enum __unnamed.conflict {
    InvalidType = 0,
    AttackType = 1,
    AnnoyType = 2,
    FlankType = 3,
    ReconType = 4,
};
enum __unnamed.conflict {
    Ok = 0,
    WaitingOnOtherMovingObject = 1,
    OkObjectOverWaypoint = 2,
    NoMoveNeeded = 3,
    Lost = 4,
    OkGoalFound = 5,
    WaitingOnTimeout = 6,
};
enum __unnamed.conflict {
    GOLD = 0,
    WOOD = 1,
    STONE = 2,
    FOOD = 3,
    POPULATION = 4,
    AGE = 5,
    EXPLORATION = 6,
};
enum __unnamed.conflict {
    NoFormat = 0,
    TimeFormat = 1,
    YearsFormat = 2,
};
enum __unnamed.conflict {
    VictoryStandard = 0,
    VictoryConquest = 1,
    VictoryScore = 2,
    VictoryTime = 3,
    VictoryCustom = 4,
};
enum __unnamed.conflict {
    SoldierAttack = 100,
    SoldierDefend = 101,
    SoldierExplore = 102,
    BoatAttack = 103,
    BoatDefend = 104,
    BoatExplore = 105,
    BoatTransport = 106,
    BoatFish = 107,
    BoatTrade = 108,
    Artifact = 109,
};
enum __unnamed.conflict {
    GroupPlacement = 0,
    UnusedLot = 0,
    StoragePitPlacement = 1,
    UsedLot = 1,
    GranaryPlacement = 2,
    InvalidLot = 2,
    PermanentlyRemoveLot = 3,
    TowerPlacement = 3,
    MaxGates = 4,
    NumberQuadrants = 4,
    WallPlacement = 4,
    ElevationValue = 5,
    GeneralBuildingPlacement = 5,
    PriorAttackValue = 5,
    NoSpaceBuildingPlacement = 6,
    DockPlacement = 7,
    FarmPlacement = 8,
    TownCenterPlacement = 9,
    BuildingLOSValue = 10,
    EdgeUnattractiveValue = 10,
    GroupLOSValue = 10,
    TerrainValue = 10,
    BasePlacementValue = 20,
    AttackMapSize = 50,
    LOSMapSize = 50,
    MinimumZoneSizeForDock = 50,
    MinimumResourceLOSValue = 64,
    MinimumLOSCoverageValue = 111,
    ResourceLOSValue = 128,
    GateValue = 254,
    Impassable = 255,
};
enum __unnamed.conflict {
    skipping = 0,
    tied = 1,
};
enum __unnamed.conflict1 {
    InvalidTarget = 0,
    StationaryTarget = 1,
    MovingTarget = 2,
    SlowTarget = 3,
    FastTarget = 4,
    AnyTarget = 5,
};
enum __unnamed.conflict1 {
    InsideRange = 0,
    InRange = 1,
    OutsideRange = 2,
};
enum __unnamed.conflict1 {
    NoWaitCode = -1,
    WaitingOnTransport = 200,
    WaitingToAttack = 201,
};
enum __unnamed.conflict1 {
    Axeman = 0,
    Infantry = 1,
    Cavalry = 2,
    Hoplite = 3,
    Siege = 4,
    Priest = 5,
    Archer = 6,
    Chariot = 7,
    Ship = 8,
    Elephant = 9,
    ChariotArcher = 10,
    NumberAIUnitTypes = 11,
};
enum __unnamed.conflict2 {
    InvalidOverflow = 0,
    BalanceOverflow = 1,
    FirstGroupOverflow = 2,
};
enum __unnamed.conflict2 {
    MaximumUserDefinedWaypoints = 5,
    ContinueCounterPathingLimit = 10,
    ContinueCounterLimit = 25,
};
enum __unnamed.conflict2 {
    MaximumAttackWaypoints = 15,
    MaxObjectsToDestroy = 20,
};
enum Action {
    OK = 0,
    Cancel = 1,
    Other = 2,
};
enum Action {
    ActionSelect = 1,
};
enum ActionType {
    ActionSelect = 1,
    ActionDown = 2,
    ActionUp = 3,
    ActionRightSelect = 4,
    ActionRightDown = 5,
    ActionRightUp = 6,
};
enum ActionType {
    ActionItem = 0,
    ActionList = 1,
    ActionValue = 2,
};
enum ActionType {
    ActionEnter = 0,
    ActionEscape = 1,
    ActionTab = 2,
};
enum ActionType {
    ActionEnter = 0,
    ActionEscape = 1,
    ActionTab = 2,
};
enum ActionType {
    ActionItem = 1,
    ActionLand = 2,
    ActionSelect = 3,
};
enum ActionType {
    ActionObjectChanged = 1,
};
enum ActionType {
    ActionUp = 0,
    ActionDown = 1,
    ActionPrior = 2,
    ActionNext = 3,
    ActionPosition = 4,
    ActionEnd = 5,
    ActionChange = 6,
};
enum ActionType {
    ActionDone = 1,
};
enum Age {
    DefaultAge = 0,
    NomadAge = 1,
    StoneAge = 2,
    ToolAge = 3,
    BronzeAge = 4,
    IronAge = 5,
};
enum Alignment {
    AlignCenter = 0,
    AlignLeft = 1,
    AlignRight = 2,
    AlignTop = 3,
    AlignBottom = 4,
    AlignHorizontalScroll = 5,
    AlignWordwrap = 6,
};
enum BevelType {
    BevelNone = 0,
    BevelFlat = 1,
    Bevel1 = 2,
    Bevel2 = 3,
    Bevel3 = 4,
};
enum BevelType {
    BevelNone = 0,
    BevelFlat = 1,
    Bevel1 = 2,
    Bevel2 = 3,
    Bevel3 = 4,
};
enum BevelType {
    BevelNone = 0,
    BevelFlat = 1,
    BevelIn1 = 2,
    BevelIn2 = 3,
    BevelIn3 = 4,
    BevelOut1 = 5,
    BevelOut2 = 6,
    BevelOut3 = 7,
};
enum BevelType {
    BevelNone = 0,
    BevelFlat = 1,
    Bevel1 = 2,
    Bevel2 = 3,
    Bevel3 = 4,
};
enum BevelType {
    BevelNone = 0,
    BevelFlat = 1,
    BevelIn1 = 2,
    BevelIn2 = 3,
    BevelIn3 = 4,
    BevelOut1 = 5,
    BevelOut2 = 6,
    BevelOut3 = 7,
};
enum BevelType {
    BevelNone = 0,
    BevelFlat = 1,
    BevelIn1 = 2,
    BevelIn2 = 3,
    BevelIn3 = 4,
    BevelOut1 = 5,
    BevelOut2 = 6,
    BevelOut3 = 7,
};
enum BrushSize {
    BrushSizeNone = 0,
    BrushSizeVerySmall = 1,
    BrushSizeSmall = 2,
    BrushSizeMedium = 3,
    BrushSizeLarge = 4,
    BrushSizeXLarge = 5,
};
enum ButtonType {
    Normal = 1,
    Radio = 2,
    State = 3,
};
enum CharType {
    SingleByteChar = 0,
    SingleByteKanaChar = 1,
    DoubleByteChar = 2,
};
enum COMMMESSAGES {
    COMM_PAUSE = 6050,
    COMM_RESUME = 6051,
    COMM_UPDATE_PLAYERS = 6052,
    COMM_UPDATE_CHAT = 6053,
    COMM_UPDATE_PARAMS = 6054,
    COMM_LAUNCH_GAME = 6055,
    COMM_CANCEL_GAME = 6056,
    COMM_HOST_EXITED = 6057,
    COMM_PLAYER_KICKED = 6058,
    COMM_NO_NEW_PLAYERS = 6059,
    COMM_FATAL_ERROR = 6060,
    COMM_CONNECTED = 6061,
    COMM_NO_LINK = 6062,
    COMM_CLIENT_IS_SLOW = 6063,
    COMM_SYNC_ERROR = 6064,
    COMM_HOST_CHANGED = 6065,
    COMM_PLAYER_DROPPED = 6066,
    COMM_OTHER_PLAYER_DROPPED = 6067,
    COMM_PLAYER_RESIGNED = 6068,
    COMM_PLAYER_DEFEATED = 6069,
    COMM_PLAYER_BAD_VERSION = 6070,
    COMM_PLAYER_SERVICE_ERROR = 6071,
    COMM_PLAYER_ID_SET = 6072,
    COMM_HOST_BUSY = 6073,
    COMM_LOBBY_TIMEOUT = 6074,
    COMM_SHARED_DATA_SENT = 6075,
    COMM_NO_OTHER_HUMANS = 6076,
    COMM_PLAYER_NOT_RESPONDING = 6077,
    COMM_UNKNOWN = 6078,
};
enum COMMSPEEDS {
    SPEED_OKAY = 0,
    SPEED_FASTER = 1,
    SPEED_SLOWER = 2,
};
enum COMMSTATES {
    COMM_STATE_ERROR = 1,
    COMM_STATE_INITIALIZE = 2,
    COMM_STATE_JOINNOW = 3,
    COMM_STATE_PAUSE = 4,
    COMM_STATE_RUNNING = 5,
    COMM_STATE_FINISHED = 6,
};
enum COMMSTATUS {
    UNINITIALIZED = 0,
    INITIALIZED = 1,
    SINGLE_PLAYER = 2,
    MULTIPLAYER_RESET = 3,
    CONVERSATION_OPEN = 4,
    SERVICE_AVAILABLE = 5,
    SESSION_AVAILABLE = 6,
    SESSION_HOSTED = 7,
    SESSION_JOINED = 8,
    PLAYER_CREATED = 9,
    COMM_SETTINGS_EXCHANGED = 10,
    GAME_PLAYER_SET = 11,
    GAME_OPTIONS_EXCHANGED = 12,
    GAME_IS_LOADING = 13,
    GAME_IS_RUNNING = 14,
    GAME_IS_PAUSED = 15,
};
enum DrawStyle {
    DrawStyleNormal = 0,
    DrawStyleLeftButton = 1,
};
enum DrawType {
    DrawClear = 1,
    DrawPicture = 2,
    DrawTextA = 3,
    DrawPictureAndText = 4,
    DrawFillAndText = 5,
    DrawBevelPicture = 6,
};
enum DropdownMode {
    ModeNone = 0,
    ModeValue = 1,
    ModeList = 2,
};
enum FormatType {
    FormatText = 0,
    FormatNumber = 1,
    FormatInteger = 2,
    FormatUnsignedInt = 3,
    FormatFile = 4,
    FormatFileNoExt = 5,
    FormatPath = 6,
    FormatMultiLine = 7,
    FormatPercent = 8,
};
enum FormatType {
    FormatText = 0,
    FormatNumber = 1,
    FormatInteger = 2,
    FormatUnsignedInt = 3,
    FormatFile = 4,
    FormatFileNoExt = 5,
    FormatPath = 6,
    FormatMultiLine = 7,
    FormatPercent = 8,
};
enum io_state {
    goodbit = 0,
    eofbit = 1,
    failbit = 2,
    badbit = 4,
};
enum ItemType {
    ItemNone = 0,
    ItemUp = 1,
    ItemDown = 2,
    ItemTab = 3,
    ItemTop = 4,
    ItemBottom = 5,
};
enum JustType {
    TopJust = 0,
    BottomJust = 1,
    LeftJust = 2,
    RightJust = 3,
    CenterJust = 4,
};
enum MapSize {
    Tiny = 0,
    Small = 1,
    Medium = 2,
    Large = 3,
    Huge = 4,
    Humongous = 5,
};
enum MapType {
    AllWater = 0,
    MostlyWater = 1,
    WaterAndLand = 2,
    MostlyLand = 3,
    AllLand = 4,
    Continental = 5,
    Lake = 6,
    Hilly = 7,
    Isthmas = 8,
};
enum MapType {
    MapTypeNone = 0,
    MapTypeBlank = 1,
    MapTypeRandom = 2,
    MapTypeSeed = 3,
};
enum MessageType {
    InfoMessage = 0,
    BadMessage = 1,
    DebugMessage = 2,
    ChatMessage = 3,
    ColoredChatMessage = 4,
    RightInfoMessage = 5,
};
enum MessageType {
    MessageTypeNone = 0,
    MessageTypeDescription = 1,
    MessageTypeInstructions = 2,
    MessageTypeVictory = 3,
    MessageTypeFailure = 4,
};
enum Mode {
    ModeNone = 0,
    ModeDown = 1,
    ModeHold = 2,
};
enum Mode {
    InGame = 0,
    InPregame = 1,
};
enum Mode {
    SaveGame = 0,
    SaveScenario = 1,
    SaveScenarioEdit = 2,
};
enum Mode {
    AsChat = 0,
    AsComment = 1,
};
enum MouseAction {
    MouseActionNone = 0,
    MouseActionDown = 1,
    MouseActionHold = 2,
    MouseActionMove = 3,
};
enum MouseButton {
    MouseButtonNone = 0,
    LeftMouseButton = 1,
    RightMouseButton = 2,
};
enum NotifyType {
    NotifyAction = 1,
    NotifyCommand = 2,
};
enum open_mode {
    in = 1,
    out = 2,
    ate = 4,
    app = 8,
    trunc = 16,
    nocreate = 32,
    noreplace = 64,
    binary = 128,
};
enum Orientation {
    Vertical = 0,
    Horizontal = 1,
};
enum PaintType {
    PaintTypeNone = 0,
    PaintTypeTerrain = 1,
    PaintTypeElevation = 2,
    PaintTypeCliffs = 3,
};
enum PathResult {
    PathFound = 0,
    NoPathFound = 1,
    WaitingOnPathingCap = 2,
};
enum PictureType {
    Picture = 0,
    Shape = 1,
};
enum PlacementResult {
    PlacementOk = 0,
    PlacementOnImpassableTile = 1,
    PlacementObstructed = 2,
    PlacementUnknownObject = 3,
    PlacementFailed = 4,
    PlacementFailedNoLot = 5,
};
enum PLAYERHUMANITY {
    ME_ABSENT = 0,
    ME_CLOSED = 1,
    ME_HUMAN = 2,
    ME_ELIMINATED = 3,
    ME_COMPUTER = 4,
    ME_CYBORG = 5,
    ME_VIEWONLY = 6,
};
enum PositionMode {
    PositionFixed = 0,
    PositionVariable = 1,
    PositionCentered = 2,
    PositionLeft = 3,
    PositionTop = 4,
    PositionRight = 5,
    PositionBottom = 6,
    PositionLeftTop = 7,
    PositionLeftBottom = 8,
    PositionRightTop = 9,
    PositionRightBottom = 10,
};
enum PROXY_PHASE {
    PROXY_CALCSIZE = 0,
    PROXY_GETBUFFER = 1,
    PROXY_MARSHAL = 2,
    PROXY_SENDRECEIVE = 3,
    PROXY_UNMARSHAL = 4,
};
enum RedrawMode {
    RedrawNone = 0,
    RedrawNormal = 1,
    RedrawFull = 2,
};
enum ResourceLevel {
    DefaultResources = 0,
    LowResource = 1,
    MediumResources = 2,
    HighResources = 3,
    VeryHighResources = 4,
};
enum ScenarioMode {
    ScenarioModeNone = 0,
    ScenarioModeMap = 1,
    ScenarioModeTerrain = 2,
    ScenarioModePlayers = 3,
    ScenarioModeUnits = 4,
    ScenarioModeDiplomacy = 5,
    ScenarioModeVictory = 6,
    ScenarioModeVictoryMulti = 7,
    ScenarioModeOptions = 8,
    ScenarioModeMessages = 9,
    ScenarioModeCinematics = 10,
    ScenarioModeSave = 11,
};
enum ScreenMode {
    ModeNone = 1,
    ModeFadeOut = 2,
    ModeFadeOutDone = 3,
    ModePause = 4,
    ModeFadeIn = 5,
};
enum ScrollAction {
    ScrollCount = 0,
    ScrollLine = 1,
    ScrollDown = 2,
    ScrollUp = 3,
    ScrollNext = 4,
    ScrollPrior = 5,
    ScrollHome = 6,
    ScrollEnd = 7,
};
enum SectionFlags {
    IMAGE_SCN_TYPE_NO_PAD = 8,
    IMAGE_SCN_RESERVED_0001 = 16,
    IMAGE_SCN_CNT_CODE = 32,
    IMAGE_SCN_CNT_INITIALIZED_DATA = 64,
    IMAGE_SCN_CNT_UNINITIALIZED_DATA = 128,
    IMAGE_SCN_LNK_OTHER = 256,
    IMAGE_SCN_LNK_INFO = 512,
    IMAGE_SCN_RESERVED_0040 = 1024,
    IMAGE_SCN_LNK_REMOVE = 2048,
    IMAGE_SCN_LNK_COMDAT = 4096,
    IMAGE_SCN_GPREL = 32768,
    IMAGE_SCN_MEM_16BIT = 131072,
    IMAGE_SCN_MEM_PURGEABLE = 131072,
    IMAGE_SCN_MEM_LOCKED = 262144,
    IMAGE_SCN_MEM_PRELOAD = 524288,
    IMAGE_SCN_ALIGN_1BYTES = 1048576,
    IMAGE_SCN_ALIGN_2BYTES = 2097152,
    IMAGE_SCN_ALIGN_4BYTES = 3145728,
    IMAGE_SCN_ALIGN_8BYTES = 4194304,
    IMAGE_SCN_ALIGN_16BYTES = 5242880,
    IMAGE_SCN_ALIGN_32BYTES = 6291456,
    IMAGE_SCN_ALIGN_64BYTES = 7340032,
    IMAGE_SCN_ALIGN_128BYTES = 8388608,
    IMAGE_SCN_ALIGN_256BYTES = 9437184,
    IMAGE_SCN_ALIGN_512BYTES = 10485760,
    IMAGE_SCN_ALIGN_1024BYTES = 11534336,
    IMAGE_SCN_ALIGN_2048BYTES = 12582912,
    IMAGE_SCN_ALIGN_4096BYTES = 13631488,
    IMAGE_SCN_ALIGN_8192BYTES = 14680064,
    IMAGE_SCN_LNK_NRELOC_OVFL = 16777216,
    IMAGE_SCN_MEM_DISCARDABLE = 33554432,
    IMAGE_SCN_MEM_NOT_CACHED = 67108864,
    IMAGE_SCN_MEM_NOT_PAGED = 134217728,
    IMAGE_SCN_MEM_SHARED = 268435456,
    IMAGE_SCN_MEM_EXECUTE = 536870912,
    IMAGE_SCN_MEM_READ = 1073741824,
    IMAGE_SCN_MEM_WRITE = 2147483648,
};
enum seek_dir {
    beg = 0,
    cur = 1,
    end = 2,
};
enum SELECT_REGION_e {
    SELECT_OFF = 0,
    SELECT_OBJECT = 1,
    SELECT_DEST_OBJECT = 2,
    SELECT_AREA = 3,
};
enum SliderAction {
    ActionUp = 0,
    ActionDown = 1,
    ActionStartSlide = 2,
    ActionEndSlide = 3,
    ActionSelect = 4,
};
enum State {
    StateScenario = 0,
    StateRandom = 1,
};
enum STUB_PHASE {
    STUB_UNMARSHAL = 0,
    STUB_CALL_SERVER = 1,
    STUB_MARSHAL = 2,
    STUB_CALL_SERVER_NO_HRESULT = 3,
};
enum Style {
    NormalStyle = 0,
    BeveledStyle = 1,
    ChiseledStyle = 2,
};
enum Style {
    NormalStyle = 0,
    BeveledStyle = 1,
    ChiseledStyle = 2,
};
enum Type {
    OKDialog = 0,
    OKCancelDialog = 1,
    YesNoDialog = 2,
    RetryAbortDialog = 3,
    YesNoCancelDialog = 4,
};
enum ValueType {
    ValueTypeNumber = 0,
    ValueTypeBonus = 1,
    ValueTypeCompare = 2,
    ValueTypePercent = 3,
    ValueTypeNone = 4,
};
enum VictoryType {
    VictoryDefault = 0,
    VictoryConquest = 1,
    VictoryExplore = 2,
    VictoryRuins = 3,
    VictoryArtifacts = 4,
    VictoryDiscoveries = 5,
    VictoryGold = 6,
    VictoryTime = 7,
    VictoryScore = 8,
    VictoryStandard = 9,
};
enum VictoryType {
    VictoryTypeNone = 0,
    VictoryTypeStandard = 1,
    VictoryTypeConquest = 2,
    VictoryTypeScore = 3,
    VictoryTypeTime = 4,
    VictoryTypeCustom = 5,
};
enum XLAT_SIDE {
    XLAT_SERVER = 1,
    XLAT_CLIENT = 2,
};
enum ZOrder {
    ZOrderPosition = 0,
    ZOrderTop = 1,
    ZOrderBottom = 2,
};
struct __unnamed {
};
struct __unnamed {
    float from_angle1;
    float to_angle1;
    float from_angle2;
    float to_angle2;
    float line_x1;
    float line_y1;
    float line_x2;
    float line_y2;
};
struct __unnamed {
    short player_id;
    TRIBE_Player * player;
    TRIBE_Building_Object * port;
    short money;
};
struct __unnamed {
    ulong dwType;
    ulong dwDeviceID;
    ushort wMid;
    ushort wPid;
    uint vDriverVersion;
    char[32] szPname;
};
struct __unnamed_s_0 {
    long lMinimum;
    long lMaximum;
};
struct __unnamed_s_1 {
    ulong dwMinimum;
    ulong dwMaximum;
};
struct _CONTEXT {
};
struct _DDBLTBATCH {
    tagRECT * lprDest;
    IDirectDrawSurface * lpDDSSrc;
    tagRECT * lprSrc;
    ulong dwFlags;
    _DDBLTFX * lpDDBltFx;
};
struct _DDBLTFX {
    ulong dwSize;
    ulong dwDDFX;
    ulong dwROP;
    ulong dwDDROP;
    ulong dwRotationAngle;
    ulong dwZBufferOpCode;
    ulong dwZBufferLow;
    ulong dwZBufferHigh;
    ulong dwZBufferBaseDest;
    ulong dwZDestConstBitDepth;
    ulong dwZSrcConstBitDepth;
    ulong dwAlphaEdgeBlendBitDepth;
    ulong dwAlphaEdgeBlend;
    ulong dwReserved;
    ulong dwAlphaDestConstBitDepth;
    ulong dwAlphaSrcConstBitDepth;
    _DDCOLORKEY ddckDestColorkey;
    _DDCOLORKEY ddckSrcColorkey;
};
struct _DDCAPS {
    ulong dwSize;
    ulong dwCaps;
    ulong dwCaps2;
    ulong dwCKeyCaps;
    ulong dwFXCaps;
    ulong dwFXAlphaCaps;
    ulong dwPalCaps;
    ulong dwSVCaps;
    ulong dwAlphaBltConstBitDepths;
    ulong dwAlphaBltPixelBitDepths;
    ulong dwAlphaBltSurfaceBitDepths;
    ulong dwAlphaOverlayConstBitDepths;
    ulong dwAlphaOverlayPixelBitDepths;
    ulong dwAlphaOverlaySurfaceBitDepths;
    ulong dwZBufferBitDepths;
    ulong dwVidMemTotal;
    ulong dwVidMemFree;
    ulong dwMaxVisibleOverlays;
    ulong dwCurrVisibleOverlays;
    ulong dwNumFourCCCodes;
    ulong dwAlignBoundarySrc;
    ulong dwAlignSizeSrc;
    ulong dwAlignBoundaryDest;
    ulong dwAlignSizeDest;
    ulong dwAlignStrideAlign;
    ulong[8] dwRops;
    _DDSCAPS ddsCaps;
    ulong dwMinOverlayStretch;
    ulong dwMaxOverlayStretch;
    ulong dwMinLiveVideoStretch;
    ulong dwMaxLiveVideoStretch;
    ulong dwMinHwCodecStretch;
    ulong dwMaxHwCodecStretch;
    ulong dwReserved1;
    ulong dwReserved2;
    ulong dwReserved3;
    ulong dwSVBCaps;
    ulong dwSVBCKeyCaps;
    ulong dwSVBFXCaps;
    ulong[8] dwSVBRops;
    ulong dwVSBCaps;
    ulong dwVSBCKeyCaps;
    ulong dwVSBFXCaps;
    ulong[8] dwVSBRops;
    ulong dwSSBCaps;
    ulong dwSSBCKeyCaps;
    ulong dwSSBFXCaps;
    ulong[8] dwSSBRops;
    ulong dwReserved4;
    ulong dwReserved5;
    ulong dwReserved6;
};
struct _DDCOLORKEY {
    ulong dwColorSpaceLowValue;
    ulong dwColorSpaceHighValue;
};
struct _DDOVERLAYFX {
    ulong dwSize;
    ulong dwAlphaEdgeBlendBitDepth;
    ulong dwAlphaEdgeBlend;
    ulong dwReserved;
    ulong dwAlphaDestConstBitDepth;
    ulong dwAlphaSrcConstBitDepth;
    _DDCOLORKEY dckDestColorkey;
    _DDCOLORKEY dckSrcColorkey;
    ulong dwDDFX;
    ulong dwFlags;
};
struct _DDPIXELFORMAT {
    ulong dwSize;
    ulong dwFlags;
    ulong dwFourCC;
};
struct _DDSCAPS {
    ulong dwCaps;
};
struct _DDSURFACEDESC {
    ulong dwSize;
    ulong dwFlags;
    ulong dwHeight;
    ulong dwWidth;
    ulong dwBackBufferCount;
    ulong dwAlphaBitDepth;
    ulong dwReserved;
    void * lpSurface;
    _DDCOLORKEY ddckCKDestOverlay;
    _DDCOLORKEY ddckCKDestBlt;
    _DDCOLORKEY ddckCKSrcOverlay;
    _DDCOLORKEY ddckCKSrcBlt;
    _DDPIXELFORMAT ddpfPixelFormat;
    _DDSCAPS ddsCaps;
};
struct _DIDATAFORMAT {
    ulong dwSize;
    ulong dwObjSize;
    ulong dwFlags;
    ulong dwDataSize;
    ulong dwNumObjs;
    _DIOBJECTDATAFORMAT * rgodf;
};
struct _DIOBJECTDATAFORMAT {
    _GUID * pguid;
    ulong dwOfs;
    ulong dwType;
    ulong dwFlags;
};
struct _DSBCAPS {
    ulong dwSize;
    ulong dwFlags;
    ulong dwBufferBytes;
    ulong dwUnlockTransferRate;
    ulong dwPlayCpuOverhead;
};
struct _DSBUFFERDESC {
    ulong dwSize;
    ulong dwFlags;
    ulong dwBufferBytes;
    ulong dwReserved;
    tWAVEFORMATEX * lpwfxFormat;
};
struct _DSCAPS {
    ulong dwSize;
    ulong dwFlags;
    ulong dwMinSecondarySampleRate;
    ulong dwMaxSecondarySampleRate;
    ulong dwPrimaryBuffers;
    ulong dwMaxHwMixingAllBuffers;
    ulong dwMaxHwMixingStaticBuffers;
    ulong dwMaxHwMixingStreamingBuffers;
    ulong dwFreeHwMixingAllBuffers;
    ulong dwFreeHwMixingStaticBuffers;
    ulong dwFreeHwMixingStreamingBuffers;
    ulong dwMaxHw3DAllBuffers;
    ulong dwMaxHw3DStaticBuffers;
    ulong dwMaxHw3DStreamingBuffers;
    ulong dwFreeHw3DAllBuffers;
    ulong dwFreeHw3DStaticBuffers;
    ulong dwFreeHw3DStreamingBuffers;
    ulong dwTotalHwMemBytes;
    ulong dwFreeHwMemBytes;
    ulong dwMaxContigFreeHwMemBytes;
    ulong dwUnlockTransferRateHwBuffers;
    ulong dwPlayCpuOverheadSwBuffers;
    ulong dwReserved1;
    ulong dwReserved2;
};
struct _EXCEPTION_POINTERS {
};
struct _FILETIME {
    ulong dwLowDateTime;
    ulong dwHighDateTime;
};
struct _finddata_t {
    uint attrib;
    long time_create;
    long time_access;
    long time_write;
    ulong size;
    char[260] name;
};
struct _GUID {
    ulong Data1;
    ushort Data2;
    ushort Data3;
    uchar[8] Data4;
};
struct _iobuf {
    char * _ptr;
    int _cnt;
    char * _base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char * _tmpfname;
};
struct _MEMORYSTATUS {
    ulong dwLength;
    ulong dwMemoryLoad;
    ulong dwTotalPhys;
    ulong dwAvailPhys;
    ulong dwTotalPageFile;
    ulong dwAvailPageFile;
    ulong dwTotalVirtual;
    ulong dwAvailVirtual;
};
struct _MMCKINFO {
    ulong ckid;
    ulong cksize;
    ulong fccType;
    ulong dwDataOffset;
    ulong dwFlags;
};
struct _MMIOINFO {
    ulong dwFlags;
    ulong fccIOProc;
    void * pIOProc;
    uint wErrorRet;
    void * htask;
    long cchBuffer;
    char * pchBuffer;
    char * pchNext;
    char * pchEndRead;
    char * pchEndWrite;
    long lBufOffset;
    long lDiskOffset;
    ulong[3] adwInfo;
    ulong dwReserved1;
    ulong dwReserved2;
    void * hmmio;
};
struct _OFSTRUCT {
    uchar cBytes;
    uchar fFixedDisk;
    ushort nErrCode;
    ushort Reserved1;
    ushort Reserved2;
    char[128] szPathName;
};
struct _OSVERSIONINFOA {
    ulong dwOSVersionInfoSize;
    ulong dwMajorVersion;
    ulong dwMinorVersion;
    ulong dwBuildNumber;
    ulong dwPlatformId;
    char[128] szCSDVersion;
};
struct _RGNDATA {
    _RGNDATAHEADER rdh;
    char[1] Buffer;
};
struct _RGNDATAHEADER {
    ulong dwSize;
    ulong iType;
    ulong nCount;
    ulong nRgnSize;
    tagRECT rcBound;
};
struct _s_FuncInfo {
};
struct _s_TryBlockMapEntry {
};
struct _SYSTEMTIME {
    ushort wYear;
    ushort wMonth;
    ushort wDayOfWeek;
    ushort wDay;
    ushort wHour;
    ushort wMinute;
    ushort wSecond;
    ushort wMilliseconds;
};
struct _tag_wavheader {
    uchar[4] szRIFF;
    ulong dwFormatLength;
    uchar[4] szWAVE;
    uchar[4] szFMT;
    ulong dwWaveFormatLength;
    short wFormatTag;
    short nChannels;
    ulong nSamplesPerSec;
    ulong nAvgBytesPerSec;
    short nBlockAlign;
    short wBitsPerSample;
    uchar[4] szDATA;
    ulong dwDataLength;
};
struct _WIN32_FIND_DATAA {
    ulong dwFileAttributes;
    _FILETIME ftCreationTime;
    _FILETIME ftLastAccessTime;
    _FILETIME ftLastWriteTime;
    ulong nFileSizeHigh;
    ulong nFileSizeLow;
    ulong dwReserved0;
    ulong dwReserved1;
    char[260] cFileName;
    char[14] cAlternateFileName;
};
struct AIModule {
    AIModuleID idValue;
    int playerNumberValue;
    char[64] playerNameValue;
    int runningValue;
    int pausedValue;
    int logHistoryValue;
    int logCommonHistoryValue;
    _iobuf * historyLogFile;
    char[64] historyLogFilename;
    int intelligenceLevelValue;
    int priorityValue;
    int processFrameValue;
};
struct AIModuleID {
    int id;
    char[64] name;
};
struct AIModuleMessage {
    int id;
    char[128] text;
    int priority;
    AIModuleID sender;
    AIModuleID recipient;
    long data1;
    long data2;
    long data3;
    AIModuleMessage * callbackMessage;
    int timeStamp;
    AIModuleMessage * next;
    AIModuleMessage * prev;
};
struct AIPlay {
    char[65] nameValue;
    uchar minimumNumberUnitsValue;
    uchar maximumNumberUnitsValue;
    uchar typeValue;
    uchar[5] targetTypeValue;
    uchar[5] targetCharacteristicValue;
    uchar powerValue;
    uchar overflowValue;
    uchar intelligenceValue;
    uchar deathPercentageValue;
    uchar numberGroupsValue;
    AIPlayGroup[5] groups;
    AIPlayPhase[10] phases;
};
struct AIPlayBook {
    int numberPlaysValue;
    char[65] nameValue;
    AIPlay * plays;
};
struct AIPlayGroup {
    uchar[6] minValue;
    uchar[6] maxValue;
};
struct AIPlayPhase {
    AIPlayPhaseCommand[5] commands;
    AIPlayPhaseTrigger[3] triggers;
};
struct AIPlayPhaseCommand {
    uchar groupValue;
    uchar typeValue;
    int value1Value;
    int value2Value;
    int value3Value;
};
struct AIPlayPhaseTrigger {
    uchar typeValue;
    int value1Value;
    int value2Value;
    uchar phaseValue;
    uchar nextPhaseValue;
    int randomnessValue;
};
struct AIPlayStatus {
    GroupingStruct[50] groupings;
    int playNumberValue;
    int targetValue;
    XYZ originalPointValue;
    int[5] originalHitPointsValue;
    uchar currentPhaseValue;
    int savedAttackerValue;
    ulong lastPhaseChangeTimeValue;
    uchar deviationValue;
};
struct AttackMemory {
    int id;
    uchar type;
    uchar minX;
    uchar minY;
    uchar maxX;
    uchar maxY;
    uchar attackingOwner;
    uchar targetOwner;
    short kills;
    uchar success;
    ulong timeStamp;
    int play;
};
struct AttackState {
    int bestTargetID;
    float bestTargetValue;
    int bestTargetMemoryIndex;
    int iterationIndex;
    int attackGroupID;
    int playID;
    uchar phase;
    int bestNonWallTargetID;
    float bestNonWallTargetValue;
    int bestNonWallTargetMemoryIndex;
    int active;
};
struct Attribute_Cost {
    short type;
    short amount;
    uchar flag;
};
struct BaseItem {
    int typeIDValue;
    int gameIDValue;
    int uniqueIDValue;
    char[64] nameValue;
    float xValue;
    float yValue;
    float zValue;
    float xSizeValue;
    float ySizeValue;
    float zSizeValue;
    int skipValue;
};
struct BaseObject {
    BaseObject * next;
    BaseObject * prev;
    int numberGroupsValue;
    int * groupIDValue;
    int categoryIDValue;
    int typeIDValue;
    int gameIDValue;
    char[64] nameValue;
    float xPositionValue;
    float yPositionValue;
    float zPositionValue;
    float xSizeValue;
    float ySizeValue;
    float zSizeValue;
    int hitPointValue;
    int minHitPointValue;
    int maxHitPointValue;
    int busyValue;
    int currentTaskValue;
    int currentTargetValue;
    int currentTargetTypeValue;
    float currentTargetXPositionValue;
    float currentTargetYPositionValue;
    float currentTargetZPositionValue;
};
struct BITMAPINFO256 {
    tagBITMAPINFOHEADER bmiHeader;
    tagRGBQUAD[256] bmiColors;
};
struct Blit_Queue_Entry {
    tagRECT src;
    tagRECT dest;
};
struct BuildAIModule {
    BuildItem buildList;
    int buildListLengthValue;
    char[257] buildListNameValue;
    char[257] lastBuildItemRequestedValue;
    char[257] currentBuildItemRequestedValue;
    char[257] nextBuildItemRequestedValue;
    int numberItemsIntoBuildListValue;
    ManagedArray<int> typesToIgnore;
};
struct BuildingLot {
    int typeID;
    uchar status;
    uchar x;
    uchar y;
};
struct BuildItem {
    BuildItem * next;
    BuildItem * prev;
    int buildCategoryValue;
    int numberValue;
    int priorityValue;
    int progressValue;
    int builtValue;
    int buildAttemptsValue;
    int buildFromValue;
    int terrainSetValue;
    int[2] terrainAdjacencyValue;
    int placeOnElevationValue;
    int numberBuildsValue;
    int buildCapValue;
    int skipCyclesValue;
    uchar permanentSkipValue;
};
struct BuildRes_id_node {
    ulong id;
    int dataOffset;
    uchar * resData;
    int resSize;
    BuildRes_id_node * next;
    char[260] fName;
};
struct BuildRes_type_node {
    ulong type;
    int idOffset;
    int nIds;
    BuildRes_id_node * idList;
    BuildRes_type_node * next;
};
struct BYTEPoint {
    uchar x;
    uchar y;
};
struct CCDAudio {
    void * m_Wnd;
    int m_bOpened;
    uint m_nDeviceID;
    tagMCI_PLAY_PARMS m_mciPlayParms;
};
struct CHECKSUMARRAY {
    uint PlayerNo;
    ulong WTime;
    ulong WTurn;
    long cs1;
    long cs2;
    long cs3;
    long cs4;
    long cs5;
    uint Random;
};
struct CombatRuleSystem {
    uchar[2500] ratingValue;
};
struct combined_options {
    RGE_Game_Options rge_options;
    TRIBE_Game_Options tribe_options;
};
struct combined_options {
    RGE_Game_Options rge_options;
    TRIBE_Game_Options tribe_options;
};
struct COMMPLAYEROPTIONS {
    uchar NeedsToBeSent;
    ulong LastSentTime;
    COMMSTATES ProgramState;
    ulong CurrentTurn;
    uchar TurnSpeedMsec;
    ulong[10] dcoID;
    ulong AcknowledgeAfterMsec;
    uchar CommandTurnIncrement;
    int[10] PlayerReady;
    ulong[10] User1;
    ulong[10] User2;
    ulong[10] User3;
    ulong[10] User4;
    ulong[10] User5;
    ulong[10] User6;
    ulong[10] User7;
    PLAYERHUMANITY[10] Humanity;
    uchar[10] InvalidPlayer;
    ulong Initialized;
    ulong RandomSeed;
    ushort HighPlayerNumber;
    ushort LowPlayerNumber;
    uint HostPlayerNumber;
    int GameHasStarted;
    ulong DataSizeToFollow;
};
struct ConstructionAIModule {
    int numberConstructionLotsValue;
    ConstructionItem constructionLots;
    int numberRandomConstructionLotsValue;
    ConstructionItem randomConstructionLots;
    char[257] constructionPlanNameValue;
    float xReferencePointValue;
    float yReferencePointValue;
    float zReferencePointValue;
    int mapXSizeValue;
    int mapYSizeValue;
    PlacementResult lastPlacementReturnCodeValue;
};
struct ConstructionItem {
    ConstructionItem * next;
    ConstructionItem * prev;
    int inProgressValue;
    int builtValue;
    int buildAttemptsValue;
};
struct DClipInfo_List {
    DClipInfo_Node * * Zone_Ptrs;
    int * Zone_Size_Ptrs;
    int Used_Zones;
    int Max_Zones;
    DClipInfo_Node * Free_Head;
    int Free_Pool_Zone;
    int Free_Pool_Index;
    int Total_Blocks;
    int Free_Blocks;
    int Default_Grow_Size;
    int Element_Size;
    int Alloc_Count;
    int Dealloc_Count;
    int NewZone_Count;
    int Reset_Count;
    int SD_XMin;
    int SD_XMax;
    int SD_YMin;
    int SD_YMax;
    int Max_Draw_Levels;
    int Accept_Min_Level;
    int Accept_Max_Level;
    DClipInfo_Node * * Draw_Clip_Nodes;
    DClipInfo_Node * * Draw_Level_Head;
    DClipInfo_Node * * Draw_Level_Tail;
    int YLine_Offset;
    int YLine_Size;
    short * Select_Box;
};
struct DClipInfo_Node {
    DClipInfo_Node * Next;
    DClipInfo_Node * NextOnLevel;
    int Object_ID;
    Shape_Info * Shape;
    int Draw_Level;
    int Draw_X;
    int Draw_Y;
    int Draw_Flag;
    uchar * Shape_Base;
    uchar * Color_Table;
    int Xform_Mask;
    int Node_Type;
    short x1;
    short y1;
    short x2;
    short y2;
    short x3;
    short y3;
    short x4;
    short y4;
};
struct DIDEVCAPS {
    ulong dwSize;
    ulong dwFlags;
    ulong dwDevType;
    ulong dwAxes;
    ulong dwButtons;
    ulong dwPOVs;
    ulong dwFFSamplePeriod;
    ulong dwFFMinTimeResolution;
    ulong dwFirmwareRevision;
    ulong dwHardwareRevision;
    ulong dwFFDriverVersion;
};
struct DIDEVICEINSTANCEA {
    ulong dwSize;
    _GUID guidInstance;
    _GUID guidProduct;
    ulong dwDevType;
    char[260] tszInstanceName;
    char[260] tszProductName;
    _GUID guidFFDriver;
    ushort wUsagePage;
    ushort wUsage;
};
struct DIDEVICEOBJECTDATA {
    ulong dwOfs;
    ulong dwData;
    ulong dwTimeStamp;
    ulong dwSequence;
};
struct DIDEVICEOBJECTINSTANCEA {
    ulong dwSize;
    _GUID guidType;
    ulong dwOfs;
    ulong dwType;
    ulong dwFlags;
    char[260] tszName;
    ulong dwFFMaxForce;
    ulong dwFFForceResolution;
    ushort wCollectionNumber;
    ushort wDesignatorIndex;
    ushort wUsagePage;
    ushort wUsage;
    ulong dwDimension;
    ushort wExponent;
    ushort wReserved;
};
struct DiplomacyAIModule {
    MainDecisionAIModule * md;
    int[10] dislikeTable;
    int[10] likeTable;
    uchar[10] changeableTable;
};
struct DIPROPHEADER {
    ulong dwSize;
    ulong dwHeaderSize;
    ulong dwObj;
    ulong dwHow;
};
struct DisplaySelectedObjRec {
    int active;
    int id;
    ulong start_time;
    ulong duration;
    int select_type;
};
struct DKeyString {
    DString keyValue;
    DString valueValue;
};
struct DPCAPS {
    ulong dwSize;
    ulong dwFlags;
    ulong dwMaxBufferSize;
    ulong dwMaxQueueSize;
    ulong dwMaxPlayers;
    ulong dwHundredBaud;
    ulong dwLatency;
    ulong dwMaxLocalPlayers;
    ulong dwHeaderLength;
    ulong dwTimeout;
};
struct DPCHAT {
    ulong dwSize;
    ulong dwFlags;
};
struct DPCOMPOUNDADDRESSELEMENT {
    _GUID guidDataType;
    ulong dwDataSize;
    void * lpData;
};
struct DPCREDENTIALS {
    ulong dwSize;
    ulong dwFlags;
};
struct DPLAPPINFO {
    ulong dwSize;
    _GUID guidApplication;
};
struct DPLCONNECTION {
    ulong dwSize;
    ulong dwFlags;
    DPSESSIONDESC2 * lpSessionDesc;
    DPNAME * lpPlayerName;
    _GUID guidSP;
    void * lpAddress;
    ulong dwAddressSize;
};
struct DPNAME {
    ulong dwSize;
    ulong dwFlags;
};
struct DPSECURITYDESC {
    ulong dwSize;
    ulong dwFlags;
    ulong dwCAPIProviderType;
    ulong dwEncryptionAlgorithm;
};
struct DPSESSIONDESC {
    ulong dwSize;
    _GUID guidSession;
    ulong dwSession;
    ulong dwMaxPlayers;
    ulong dwCurrentPlayers;
    ulong dwFlags;
    char[32] szSessionName;
    char[16] szUserField;
    ulong dwReserved1;
    char[16] szPassword;
    ulong dwReserved2;
    ulong dwUser1;
    ulong dwUser2;
    ulong dwUser3;
    ulong dwUser4;
};
struct DPSESSIONDESC2 {
    ulong dwSize;
    ulong dwFlags;
    _GUID guidInstance;
    _GUID guidApplication;
    ulong dwMaxPlayers;
    ulong dwCurrentPlayers;
    ulong dwReserved1;
    ulong dwReserved2;
    ulong dwUser1;
    ulong dwUser2;
    ulong dwUser3;
    ulong dwUser4;
};
struct DrawAreaNode {
    TDrawArea * DrawArea;
    DrawAreaNode * PrevNode;
    DrawAreaNode * NextNode;
};
struct DriveInformation {
    int initialDriveValue;
    char[256] initialDirectoryValue;
    int currentDriveValue;
    char[256] currentDirectoryValue;
    int[27] driveValues;
};
struct DString {
    char * stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;
};
struct EHExceptionRecord {
};
struct EHRegistrationNode {
};
struct EmotionalAIModule {
    MainDecisionAIModule * md;
    int[6] stateValue;
    char[6][30] stateNameValue;
};
struct FlicHead {
    long size;
    ushort type;
    short frames;
    short width;
    short height;
    short depth;
    short flags;
    long speed;
    short reserved1;
    long created;
    long creator;
    long updated;
    long updater;
    short aspect_dx;
    short aspect_dy;
    char[38] reserved2;
    char * oframe1;
    char * oframe2;
    char[40] reserved3;
};
struct FloatHeap {
    uchar x;
    uchar y;
    float total;
};
struct FrameHead {
    long size;
    short type;
    short chunks;
    char[8] reserved;
};
struct Friendliness {
    int[16] Attitude;
};
struct GroupingStruct {
    int id;
    uchar groupID;
    uchar type;
};
struct HOLDER {
    char * HoldMsg;
    uint Serial;
    uint Length;
    ulong dcoFromID;
    ulong dcoReceiveID;
    uint fromPlayer;
};
struct ICINFO {
    ulong dwSize;
    ulong fccType;
    ulong fccHandler;
    ulong dwFlags;
    ulong dwVersion;
    ulong dwVersionICM;
    ushort[16] szName;
    ushort[128] szDescription;
    ushort[128] szDriver;
};
struct IDirectDraw {
};
struct IDirectDraw2 {
};
struct IDirectDrawClipper {
};
struct IDirectDrawPalette {
};
struct IDirectDrawSurface {
};
struct IDirectDrawSurface3 {
};
struct IDirectInputA {
};
struct IDirectInputDeviceA {
};
struct IDirectPlay {
};
struct IDirectPlay2 {
};
struct IDirectPlay3 {
};
struct IDirectPlayLobby {
};
struct IDirectPlayLobby2 {
};
struct IDirectSound {
};
struct IDirectSoundBuffer {
};
struct IMAGE_DATA_DIRECTORY {
    ImageBaseOffset32 VirtualAddress;
    dword Size;
};
struct IMAGE_DEBUG_DIRECTORY {
    dword Characteristics;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    dword Type;
    dword SizeOfData;
    dword AddressOfRawData;
    dword PointerToRawData;
};
struct IMAGE_DOS_HEADER {
    char[2] e_magic;
    word e_cblp;
    word e_cp;
    word e_crlc;
    word e_cparhdr;
    word e_minalloc;
    word e_maxalloc;
    word e_ss;
    word e_sp;
    word e_csum;
    word e_ip;
    word e_cs;
    word e_lfarlc;
    word e_ovno;
    word[4] e_res[4];
    word e_oemid;
    word e_oeminfo;
    word[10] e_res2[10];
    dword e_lfanew;
    byte[64] e_program;
};
struct IMAGE_FILE_HEADER {
    word Machine;
    word NumberOfSections;
    dword TimeDateStamp;
    dword PointerToSymbolTable;
    dword NumberOfSymbols;
    word SizeOfOptionalHeader;
    word Characteristics;
};
struct IMAGE_NT_HEADERS32 {
    char[4] Signature;
    IMAGE_FILE_HEADER FileHeader;
    IMAGE_OPTIONAL_HEADER32 OptionalHeader;
};
struct IMAGE_OPTIONAL_HEADER32 {
    word Magic;
    byte MajorLinkerVersion;
    byte MinorLinkerVersion;
    dword SizeOfCode;
    dword SizeOfInitializedData;
    dword SizeOfUninitializedData;
    ImageBaseOffset32 AddressOfEntryPoint;
    ImageBaseOffset32 BaseOfCode;
    ImageBaseOffset32 BaseOfData;
    pointer32 ImageBase;
    dword SectionAlignment;
    dword FileAlignment;
    word MajorOperatingSystemVersion;
    word MinorOperatingSystemVersion;
    word MajorImageVersion;
    word MinorImageVersion;
    word MajorSubsystemVersion;
    word MinorSubsystemVersion;
    dword Win32VersionValue;
    dword SizeOfImage;
    dword SizeOfHeaders;
    dword CheckSum;
    word Subsystem;
    word DllCharacteristics;
    dword SizeOfStackReserve;
    dword SizeOfStackCommit;
    dword SizeOfHeapReserve;
    dword SizeOfHeapCommit;
    dword LoaderFlags;
    dword NumberOfRvaAndSizes;
    IMAGE_DATA_DIRECTORY[16] DataDirectory;
};
struct IMAGE_RESOURCE_DATA_ENTRY {
    dword OffsetToData;
    dword Size;
    dword CodePage;
    dword Reserved;
};
struct IMAGE_RESOURCE_DIR_STRING_U_14 {
    word Length;
    unicode NameString;
};
struct IMAGE_RESOURCE_DIRECTORY {
    dword Characteristics;
    dword TimeDateStamp;
    word MajorVersion;
    word MinorVersion;
    word NumberOfNamedEntries;
    word NumberOfIdEntries;
};
struct IMAGE_RESOURCE_DIRECTORY_ENTRY_DirectoryStruct {
    dword OffsetToDirectory;
    dword DataIsDirectory;
};
struct IMAGE_RESOURCE_DIRECTORY_ENTRY_NameStruct {
    dword NameOffset;
    dword NameIsString;
};
struct IMAGE_SECTION_HEADER {
    char[8] Name;
    Misc Misc;
    ImageBaseOffset32 VirtualAddress;
    dword SizeOfRawData;
    dword PointerToRawData;
    dword PointerToRelocations;
    dword PointerToLinenumbers;
    word NumberOfRelocations;
    word NumberOfLinenumbers;
    SectionFlags Characteristics;
};
struct InfluenceMap {
    int xSizeValue;
    int ySizeValue;
    int xReferencePointValue;
    int yReferencePointValue;
    uchar * valueValue;
    uchar * * rowValue;
    int coverageCountValue;
    int connectionCountValue;
    uchar unchangeableLimitValue;
};
struct InformationAIModule {
};
struct ios {
    streambuf * bp;
    int state;
    int ispecial;
    int ospecial;
    int isfx_special;
    int osfx_special;
    int x_delbuf;
    ostream * x_tie;
    long x_flags;
    int x_precision;
    char x_fill;
    int x_width;
};
struct IPAD {
    char[32] DottedIPAddress;
    char[128] Alias;
};
struct istream {
    int _fGline;
    int x_gcount;
};
struct istream_withassign {
};
struct Item_Avail {
    char * name;
    short id;
    short pict;
    short inventory_item_1;
    float inventory_cost_1;
    short inventory_item_2;
    float inventory_cost_2;
    short inventory_item_3;
    float inventory_cost_3;
    long help_string_id;
    long help_page_id;
};
struct IUnknown {
};
struct LINEINFO {
    int AllTrans;
    int MidSolid;
    long StartX;
    long EndX;
};
struct List_Info {
    char[100] text;
    short id;
};
struct LOSTBL {
    int y_delta;
    int x_left;
    int x_right;
};
struct MainDecisionAIModule {
    RGE_Player * player;
    ManagedArray<int> objects;
};
struct ManagedArray<int> {
    int * value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};
struct Map_Stack {
    long x;
    long y;
    float cost;
    float tot_cost;
    Map_Stack * next;
    Map_Stack * prev;
};
struct MGP_FloatHeap {
    uchar x;
    uchar y;
    ushort next;
    int total;
};
struct MouseClickInfo {
    int object_group;
    int self_action;
    int self_text_id;
    int gaia_action;
    int gaia_text_id;
    int ally_action;
    int ally_text_id;
    int neutral_action;
    int neutral_text_id;
    int enemy_action;
    int enemy_text_id;
};
struct MSGFORMAT_ACKNOWLEDGE_GUARANTEED {
    uchar Command;
    uint Serialno;
};
struct MSGFORMAT_ALL_DONE {
    uchar Command;
    ulong ExecuteOnTurn;
    uchar HighLatencyCenti;
    uchar FrameRateMsec;
};
struct MSGFORMAT_CHAT {
    uchar FromGamerID;
    uchar[10] DestPlayers;
    uint TextSize;
    uchar Pregame;
    char[256] ChatMsg;
};
struct MSGFORMAT_CHECKSUM {
    ulong WorldTime;
    ulong WorldTurn;
    uint Random;
    long cs1;
    long cs2;
    long cs3;
    long cs4;
    long cs5;
    ulong PingInitiated;
};
struct MSGFORMAT_HEADER_GUARANTEED {
    uchar Command;
    uchar Sequence;
    ulong ExecuteOnTurn;
    uint Serialno;
};
struct MSGFORMAT_KILL_PLAYER {
    uint PlayerNo;
    ulong dcoID;
    ulong CurrentTurn;
};
struct MSGFORMAT_LATENCY {
    uchar Command;
    ulong Initiated;
    ulong CurrentTurn;
};
struct MSGFORMAT_MISSING_PLAYER {
    uchar Command;
    ulong PlayerID;
};
struct MSGFORMAT_ONTURN {
    ulong ExecuteOnTurn;
};
struct MSGFORMAT_RESEND {
    uchar Command;
    uint Serialno;
};
struct MSGFORMAT_SETREADYOPTIONS {
    uchar Command;
    uchar Ready;
    ulong User1;
    ulong User2;
    ulong User3;
    ulong User4;
    ulong User5;
    ulong User6;
    ulong User7;
    ulong CommunicationsVersionCode;
    uchar RGEGuaranteed;
};
struct MSGFORMAT_SPEEDCHANGE {
    ushort BufferFrames;
    ushort FrameSizeMsec;
};
struct MsgQueue {
    ulong Code;
    ulong ExecTurn;
    uchar SeqNo;
    char * msgptr;
    uint From;
    uint Size;
    int ControlCommand;
};
struct NAME {
    char[128] Text;
};
struct NotifyEvent {
    int caller;
    int recipient;
    int mType;
    long p1;
    long p2;
    long p3;
};
struct ObjectMemory {
    int id;
    short type;
    short group;
    uchar x;
    uchar y;
    uchar z;
    uchar owner;
    short hitPoints;
    int attackAttempts;
    uchar kills;
    float damageCapability;
    float rateOfFire;
    float range;
};
struct OldUnitData {
    int id;
    int data1;
    int data2;
    int data3;
};
struct OldUnitData2 {
    int id;
    int data1;
    int data2;
    int data3;
    int target;
};
struct OrderEvent {
    int issuer;
    int orderType;
    int priority;
    int target;
    int targetOwner;
    float targetX;
    float targetY;
    float targetZ;
    float range;
};
struct ostream {
    int x_floatused;
};
struct ostream_withassign {
};
struct Ov_Sprite_Draw_Rec {
    Ov_Sprite_Draw_Rec * next;
    Ov_Sprite_Draw_Rec * prev;
    TShape * theShape;
    int thefacet;
    int world_x;
    int world_y;
    int flags;
    int drawLevel;
    int displayfunction;
    ulong LastDrawTime;
    ulong DrawTimeInterval;
    uchar * colortable;
};
struct PAL_TABLE {
    int index;
    uchar red;
    uchar green;
    uchar blue;
    uchar reserved;
};
struct PanelNode {
    TPanel * panel;
    PanelNode * prev_node;
    PanelNode * next_node;
};
struct Path {
    ulong timeStampValue;
    Waypoint startValue;
    Waypoint goalValue;
    Waypoint * pathValue;
    int maxSizeValue;
    int currentSizeValue;
    int currentWaypointValue;
};
struct PathingSystem {
    int xSizeValue;
    int ySizeValue;
    uchar[255][255] facetValue;
    int[255][255] MGP_costValue;
    MGP_FloatHeap[65026] MGP_openPaths;
    uchar[1020][255] obstructionValue;
    uchar[255][255] miscValue;
    int numberOpenPathsValue;
    MGP_FloatHeap MGP_bestTraversedPath;
    int numberTraversedPathsValue;
    RGE_Map * mapValue;
    RGE_Game_World * worldValue;
    RGE_Moving_Object * currentObject;
    int currentObjectInObMap;
    int currentTargetID;
    float * currentTerrainTable;
    float currentXOffset;
    float currentYOffset;
    int currentTerrainException1;
    int currentTerrainException2;
    ManagedArray<int> initialCollidingObjects;
    int startOfPath;
    int checkTerrainOnFirstPass;
    XYPoint initialTile;
    XYPoint minTarget;
    XYPoint maxTarget;
    XYPoint minInitialPosition;
    XYPoint maxInitialPosition;
    float averageNumWaypoints;
    float averagePathLength;
    float averagePathIterations;
    int numAttempts;
    int numFails;
    int numSuccesses;
    int numInitialPathsValue;
    int numContinuePathsValue;
    int numCanPathsValue;
    int MGP_closestTargetDistance;
    float averageClosestTargetDistance;
    float averageSuccessTime;
    float averageFailTime;
    uchar CurrentFacetMask;
    int currentUnobstructibleGroupID;
    int currentUnobstructiblePlayerID;
    ManagedArray<int> currentUnobstructibles;
    int aiPS;
};
struct pcmwaveformat_tag {
    waveformat_tag wf;
    ushort wBitsPerSample;
};
struct PlacementState {
    int buildingTypeID;
    float buildingSize;
    char[256] buildingName;
    int builderID;
    int minimumDistance;
    int maximumDistance;
    int active;
    XYPoint bestPoint;
    int bestPointValue;
    int iterationX;
    int randomInfluence;
    BuildItem * buildItem;
};
struct PLAYER_SCORE {
    int comm_id;
    int player_id;
    int team_id;
    long player_score;
    long team_score;
};
struct Player_Start_Info {
    int Gold;
    int Wood;
    int Food;
    int Stone;
};
struct PlayerName {
    char[256] Name;
};
struct PointMaker {
    PrimaryPt Prime;
    PtToPt[500] Point;
    char * Mask_2x2;
    char * Mask_3x3;
    char * Mask_4x4;
    char * Mask_5x5;
    int x;
    int y;
    int NumSplitsPerBranch;
    int NumberOfSatellites;
    int ChanceOfNextNode;
    int MaxNumberOfBranches;
    int MaxBranchFlag;
    int Width;
    int Height;
    int MinimumNumTiles;
    int NumNodes;
    int NumTilesActuallyChosen;
    int CurrentPoint;
    int ProbabilityTiles;
    int TargetProbabilityCount;
    int ProbabilityAdd;
    int BranchRadius;
    int SatelliteRadius;
    int PrimaryRadius;
    int SizeArrays;
    int SatelliteDistance;
    int BranchDistance;
    int DirX;
    int DirY;
    int MaxNumberOfBranchLevels;
    int CurrentNumberOfBranchLevels;
    char * ExternalArray;
    char * ProbArray;
    char * PlacementArray;
    char * WritableExternalArray;
    int DoNotDrawOnFlag;
    int DrawOnOnlyFlag;
    int DrawOnlyInExternalArrayFlag;
    int DrawToOneArrayFlag;
    int BorderDepthPercentage;
    int LeftLimit;
    int RightLimit;
    int TopLimit;
    int BottomLimit;
    char SpecialLandType;
};
struct PrimaryPt {
    int x;
    int y;
};
struct Production_Queue_Record {
    short master_id;
    short unit_count;
};
struct PtToPt {
    int x;
    int y;
};
struct QuadrantLog {
    int numberExploredTiles;
    int numberAttacksOnUs;
    int numberAttacksByUs;
};
struct rdlg_list_info {
    char[100] text;
    short id;
};
struct res_file_type_info {
    char[4] extension;
    ulong rType;
};
struct ResearchAIModule {
    MainDecisionAIModule * md;
    TechnologyItem techTree;
    int techTreeLengthValue;
    char[257] techTreeNameValue;
};
struct RESENDER {
    ulong TimeSent;
    uint Serial;
    char * ResendMsg;
    uint Length;
    uint[10] DestMap;
};
struct resfile_header {
    char[40] banner_msg;
    char[4] version;
    char[12] password;
    int num_res_types;
    int directory_size;
};
struct resfile_id_dir_node {
    ulong id;
    long itemOffset;
    long itemSize;
};
struct resfile_type_dir_node {
    ulong type;
    long dirOffset;
    long numID;
};
struct ResFileHdr {
    uchar * mapped_file;
    int handle;
    resfile_header * header;
    ResFileHdr * next;
    char[260] res_name;
};
struct ResourceAIModule {
    MainDecisionAIModule * md;
    int numberResourcesValue;
    int * resourceValue;
    int * minValue;
    int * maxValue;
    int * * resourceTypesValue;
    int * numberResourceTypesValue;
};
struct ResourceItem {
    ResourceItem * next;
    ResourceItem * prev;
    int[8] valueValue;
    int[8] sortedValue;
    int[8] sortedIndexValue;
    int numberValue;
};
struct ResourceMemory {
    int id;
    uchar x;
    uchar y;
    uchar gatherAttempts;
    int gatherValue;
    uchar valid;
    uchar gone;
    uchar dropDistance;
    uchar resourceType;
    int dropsiteID;
};
struct RGE_Action {
    short action_type;
    RGE_Action_Object * obj;
    uchar state;
    RGE_Static_Object * target_obj;
    RGE_Static_Object * target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    RGE_Task * task;
    RGE_Action_List * sub_actions;
    RGE_Sprite * sprite;
    uchar subActionValue;
};
struct RGE_Action_Attack {
    RGE_Sprite * move_sprite;
    RGE_Sprite * fight_sprite;
    RGE_Sprite * wait_sprite;
    float range;
    float min_range;
    short missile_id;
    short fire_missile_at_frame;
    uchar need_to_attack;
    uchar was_same_owner;
    uchar indirect_fire_flag;
};
struct RGE_Action_Bird {
};
struct RGE_Action_Enter {
};
struct RGE_Action_Explore {
};
struct RGE_Action_Gather {
    int targetType;
};
struct RGE_Action_List {
    RGE_Action_Object * obj;
    RGE_Action_Node * list;
};
struct RGE_Action_Make {
};
struct RGE_Action_Missile {
    float velocity_x;
    float velocity_y;
    float velocity_z;
    float ballistic_velocity;
    float ballistic_acceleration;
};
struct RGE_Action_Move_To {
    float range;
};
struct RGE_Action_Node {
    RGE_Action * action;
    RGE_Action_Node * next;
};
struct RGE_Action_Object {
    uchar waiting;
    RGE_Action_List * actions;
    uchar command_flag;
    int lastActionValue;
    int lastActionStateValue;
};
struct RGE_Action_Transport {
};
struct RGE_Active_Animated_Sprite {
    short frame;
    float animate_interval;
    float animate_last;
    short last_frame;
    uchar frame_changed;
    uchar frame_looped;
    uchar animate_flag;
};
struct RGE_Active_Sprite {
    RGE_Sprite * sprite;
    uchar type;
    long offset_x;
    long offset_y;
};
struct RGE_Active_Sprite_List {
    RGE_Active_Sprite_Node * list;
    RGE_Static_Object * owner;
};
struct RGE_Active_Sprite_Node {
    RGE_Active_Sprite * node;
    uchar order;
    uchar count;
    RGE_Active_Sprite_Node * next;
};
struct RGE_Animated_Object {
    float speed;
};
struct RGE_Armor_Weapon_Info {
    short type;
    short value;
};
struct RGE_Base_Game {
    RGE_Game_Info * player_game_info;
    RGE_Scenario_File_Info * scenario_info;
    RGE_Prog_Info * prog_info;
    void * prog_window;
    int prog_ready;
    int prog_active;
    void * prog_palette;
    void * prog_mutex;
    long window_style;
    int random_game_seed;
    int random_map_seed;
    int save_random_game_seed;
    int save_random_map_seed;
    int screen_saver_enabled;
    int low_power_enabled;
    int error_code;
    int is_timer;
    TDrawSystem * draw_system;
    TDrawArea * draw_area;
    uchar outline_type;
    int custom_mouse;
    short shape_num;
    TShape * * shapes;
    TSound_Driver * sound_system;
    TMusic_System * music_system;
    short sound_num;
    TDigital * * sounds;
    uchar save_music_type;
    int save_music_track_from;
    int save_music_track_to;
    int save_music_cur_track;
    char[260] save_music_file;
    int save_music_loop;
    ulong save_music_pos;
    TCommunications_Handler * comm_handler;
    int comm_syncstop;
    int comm_droppackets;
    int comm_syncmsg;
    int comm_stepmode;
    int comm_speed;
    TDebuggingLog * debugLog;
    int log_comm;
    TRegistry * registry;
    int prog_mode;
    int game_mode;
    int sub_game_mode;
    int paused;
    TMousePointer * mouse_pointer;
    int erase_mouse;
    int mouse_blit_sync;
    int is_mouse_on;
    int windows_mouse;
    void * mouse_cursor;
    int input_enabled;
    void * input_disabled_window;
    short font_num;
    RGE_Font * fonts;
    char[261] work_dir;
    char[261] string_dll_name;
    RGE_Game_World * world;
    int render_all;
    short master_obj_id;
    short terrain_id;
    short elevation_height;
    short brush_size;
    char[256] timing_text;
    ulong frame_count;
    ulong world_update_count;
    ulong view_update_count;
    ulong last_frame_count;
    ulong last_world_update_count;
    ulong last_view_update_count;
    ulong fps;
    ulong world_update_fps;
    ulong view_update_fps;
    RGE_Timing_Info[30] timings;
    int do_show_timings;
    int do_show_comm;
    int do_show_ai;
    ulong last_view_time;
    RGE_Game_Options rge_game_options;
    int campaignGameValue;
    int savedGameValue;
    int quick_build;
    int save_check_for_cd;
    int[9] playerIDValue;
    int display_selected_ids;
    long[9] countdown_timer;
    int auto_paused;
    int save_paused;
    int non_user_pause;
    int rollover;
    float game_speed;
    int single_player_difficulty;
    uchar pathFindingValue;
    uchar[9] resigned;
    TDrawArea * map_save_area;
};
struct RGE_Border_Set {
    uchar loaded;
    uchar random;
    char[13] name;
    char[13] pict_name;
    long resource_id;
    TShape * shape;
    RGE_Sound * sound;
    uchar map_hi_color;
    uchar map_med_color;
    uchar map_low_color;
    uchar is_animated;
    short animation_frames;
    short pause_frames;
    float interval;
    float pause_between_loops;
    short frame;
    short draw_frame;
    float animate_last;
    uchar frame_changed;
    uchar drawn;
    RGE_TOB_Picts[19][12] borders;
    uchar draw_tile;
    short underlay_terrain;
    short border_style;
};
struct RGE_Campaign {
    RGE_Campaign_Header campaign_header;
    RGE_Scenario_Offset * scenario_offsets;
    char[255] filename;
};
struct RGE_Campaign_Header {
    long version;
    char[255] name;
    long scenario_num;
};
struct RGE_Campaign_Info {
    char[255] campaign_name;
    long current_scenario;
    long scenario_num;
    RGE_Scenario_Info * scenario_info;
    long last_scenario;
    RGE_Campaign * campaign;
};
struct RGE_Check_List {
    RGE_Check_Node * list;
};
struct RGE_Check_Node {
    RGE_Static_Object * node;
    float dx;
    float dy;
    uchar flag;
    RGE_Check_Node * next;
};
struct RGE_Cliffs_Hot_Spots {
    long x;
    long y;
    long radius;
};
struct RGE_Cliffs_Info {
    long number_of_cliffs;
    long number_of_cliffs_variance;
    long average_cliff_size;
    long cliff_size_variance;
    long cliff_terrain_spacing;
    long cliff_to_cliff_spacing;
    RGE_Cliffs_Hot_Spots[99] hot_spots;
    long hot_spot_num;
};
struct RGE_Color_Table {
    char[30] color_table_name;
    short resource_id;
    uchar type;
    uchar map_color;
    short id;
    uchar[256] table;
};
struct RGE_Combat_Object {
    VISIBLE_UNIT_REC *[9] VUR_Ptrs;
    ulong Unified_Map_Value;
    float attack_timer;
    uchar capture_flag;
};
struct RGE_Comm_Error {
    void * HostHWND;
    long LastReportedError;
};
struct RGE_Command {
    RGE_Game_World * world;
    uchar * last_order;
    long last_order_size;
    long last_order_time;
    TCommunications_Handler * com_hand;
};
struct RGE_Command_Add_Attribute {
    uchar command;
    uchar player_id;
    uchar attr_id;
    float attr_amount;
};
struct RGE_Command_Add_To_Group {
    uchar command;
    uchar player_id;
    int groupCommander;
    float groupRange;
    int newUnit;
};
struct RGE_Command_Add_Waypoint {
    uchar command;
    uchar player_id;
    int recipient;
    uchar numberWaypoints;
    XYZBYTEPoint[5] waypoint;
};
struct RGE_Command_AI_Order {
    uchar command;
    uchar player_id;
    uchar issuer;
    int recipient;
    short orderType;
    uchar orderPriority;
    int target;
    uchar targetOwner;
    float targetX;
    float targetY;
    float targetZ;
    float range;
    uchar immediate;
    uchar inFront;
};
struct RGE_Command_Create {
    uchar command;
    short obj_catagory;
    uchar player_id;
    float location_x;
    float location_y;
    float location_z;
};
struct RGE_Command_Create_Group {
    uchar command;
    uchar player_id;
    int groupCommander;
    float groupRange;
    int[25] unitsToGroup;
    uchar numberUnitsToGroup;
};
struct RGE_Command_Destroy_Group {
    uchar command;
    uchar player_id;
    int groupCommander;
};
struct RGE_Command_Formation {
    uchar command;
    int unitNum;
    int formationID;
};
struct RGE_Command_Give_Attribute {
    uchar command;
    uchar player_id;
    uchar to_player_id;
    uchar attr_id;
    float attr_amount;
};
struct RGE_Command_Group_AI_Order {
    uchar command;
    uchar player_id;
    uchar issuer;
    uchar recipient_count;
    short orderType;
    uchar orderPriority;
    int target;
    uchar targetOwner;
    float targetX;
    float targetY;
    float targetZ;
    float range;
    uchar immediate;
    uchar inFront;
};
struct RGE_Command_Group_Waypoint {
    uchar command;
    uchar unit_num;
    uchar x;
    uchar y;
};
struct RGE_Command_Order {
    uchar command;
    RGE_Obj_Info target;
    uchar unit_num;
    float location_x;
    float location_y;
};
struct RGE_Command_Pause {
    uchar command;
    uchar unit_num;
};
struct RGE_Command_Remove_From_Group {
    uchar command;
    uchar player_id;
    int groupCommander;
    int unit;
};
struct RGE_Command_Resign {
    uchar command;
    uchar player_id;
    uchar comm_player_id;
    uchar dropped;
};
struct RGE_Command_Stop {
    uchar command;
    uchar unit_num;
};
struct RGE_Communications_Addresses {
    TCommunications_Handler * comm;
    WSAData wsaData;
    char[128] hostname;
    int Status;
    uint AddressesAvailable;
    uint AliasesAvailable;
    IPAD * pIPAD;
};
struct RGE_Communications_Queue {
    uint QueueDepth;
    uint HighQueueDepth;
    uint MaxQSize;
    char[255] TBuff;
    ulong LastCurrentTurn;
    uchar Sequence;
    MsgQueue * Queue;
};
struct RGE_Communications_Speed {
    char[255] TBuff;
    RGE_TimeSinceLastCall * TurnTSLC;
    RGE_TimeSinceLastCall * FrameTSLC;
    TCommunications_Handler * Comm;
    double AccumDiff;
    int SpeedControlEnabled;
    uint CurrentBufferFrames;
    uint FutureBufferFrames;
    uint TotalBufferFramesRemaining;
    uint TargetTurnLengthMsec;
    uint CurrentBufferGranularity;
    uint FutureBufferGranularity;
    uint OverheadFactor;
    ulong TimeSinceLastBuffer;
    ulong FutureSpeedChangeTurn;
    ulong NextLatencyChangeTurn;
    uint[10] ActualLatency;
    uint[10] AverageTSLC;
    uchar[10] PlayerOptimalFrames;
    uchar[10] PlayerOptimalGranularity;
    ushort[10] RequestFasterOrSlower;
    ulong[10] PlayerAvgFramesMsec;
    ulong[10] PlayerHighLatencyMsec;
    ulong HighestLatencyMsec;
    uint SkipFrames;
    uint OptimalBufferFrames;
    uint OptimalBufferGranularity;
    uint DiffOffset;
    uint AllAcknowledgedBuffersRemaining;
    uint LastAdjusted;
    ulong RealTimePassed;
    ulong BufferTimePassed;
    uint DroppedFrames;
    uint DroppedFramesTurn;
    ulong AdjustmentCount;
    int LastFrameHadTime;
};
struct RGE_Communications_Synchronize {
    TCommunications_Handler * Comm;
    ulong CheckTime;
    ulong CheckTurn;
    int StopOnSyncFail;
    int DialogOnSyncFail;
    int SendChatMsgs;
    int NewData;
    int LastResult;
    uint Offset;
    int DoChecksums;
    ulong LastWorldRandom;
    ulong GameWorldChecksum;
    CHECKSUMARRAY[55] Check;
};
struct RGE_Damage_Sprite_Info {
    RGE_Sprite * sprite;
    uchar damage_percent;
    uchar flag;
};
struct RGE_Dialog_List {
    int list_type;
    short list_size;
    short list_line;
    rdlg_list_info * list_info;
    char * * list_text;
};
struct RGE_Diamond_Map {
    RGE_Game_World * world;
    RGE_Player * player;
    RGE_Map * map;
    int all_visible;
    int render_all;
    long mouse_last_x;
    long mouse_last_y;
    int repos_mouse;
    tagRECT view_rect;
    RGE_Player * last_player;
    RGE_Map_Image_Line * map_image_lines;
    RGE_Map_Tile_Row * map_tile_rows;
    short map_wid;
    short map_hgt;
    short map_image_start_y;
    short map_image_wid;
    short map_image_hgt;
    short map_tile_row_cnt;
    float map_row_step;
    float map_col_ratio;
    float map_row_ratio;
    short map_tile_draw_hgt;
    short map_tile_draw_wid;
    short view_col;
    short view_row;
    RGE_View * main_view;
    int scrolling;
    uchar fog_color;
    int draw_objects_mode;
    ulong cur_player_bit;
    int own_save_area;
    TDrawArea * save_area;
};
struct RGE_Diamond_Map_View {
};
struct RGE_Doppleganger_Creator {
    RGE_Player * owner;
    int allocated_size;
    int active_size;
    RGE_Static_Object * * Objects;
    ulong * * Map_Addresses;
    ulong * Last_Map_Value;
    int * Object_ids;
};
struct RGE_Doppleganger_Object {
    RGE_Static_Object * doppled_object;
    RGE_Color_Table * draw_color;
    RGE_Master_Static_Object * doppled_master_obj;
    int doppled_player;
    ulong * MapAddress;
    ulong LastMapValue;
    ulong CantSeeBits;
    uchar map_draw_level;
    uchar map_color;
    int doppledObjectID;
};
struct RGE_Effect {
    short id;
    char[31] name;
    short string_table_id;
    short effect_list_num;
    RGE_Effect_Command * effect_list;
};
struct RGE_Effect_Command {
    uchar command;
    short change_num1;
    short change_num2;
    short change_num3;
    float change_amount;
};
struct RGE_Effects {
    RGE_Effect * effects;
    long effect_num;
};
struct RGE_Elevation_Data {
    long elevation_num;
    RGE_Elevation_Data_Entry * elevation;
};
struct RGE_Elevation_Data_Entry {
    long elevation_percent;
    long elevation;
    long clumps;
    long spacing;
    long base_terrain_type;
    long base_elevation_type;
};
struct RGE_Elevation_Hot_Spots {
    long x;
    long y;
    long radius;
    long fade;
};
struct RGE_Elevation_Info {
    RGE_Elevation_Info_Line[99] elevation;
    long elevation_num;
    RGE_Elevation_Hot_Spots[99] hot_spots;
    long hot_spot_num;
};
struct RGE_Elevation_Info_Line {
    long elevation_size;
    long elevation;
    long clumps;
    long spacing;
    long base_elevation;
    long base_terrain_type;
};
struct RGE_Flic_Player {
    uchar * flic_buffer;
    int flic_handle;
    FlicHead flichead;
    TDrawArea * drawarea;
    long drawarea_width;
    long flic_width;
    uchar * window_buffer;
    uchar * save_buffer;
    char * chunk;
    long x1;
    long y1;
    long x2;
    long y2;
    long flic_size_x;
    long flic_size_y;
};
struct RGE_Font {
    void * font;
    long font_wid;
    long font_hgt;
};
struct RGE_Game_Info {
    long current_person;
    long people_num;
    RGE_Person_Info * * people_info;
    long campaign_num;
    RGE_Campaign * * campaigns;
    char[260] save_filename;
};
struct RGE_Game_Options {
    float versionValue;
    uchar scenarioGameValue;
    char[128] scenarioNameValue;
    uchar singlePlayerGameValue;
    uchar multiplayerGameValue;
    uchar mapXSizeValue;
    uchar mapYSizeValue;
    uchar mapZSizeValue;
    uchar allowCheatCodesValue;
    uchar mpPathFindingValue;
    uchar cheatNotificationValue;
    uchar fullVisibilityValue;
    uchar fogOfWarValue;
    uchar coloredChatValue;
    uchar numberPlayersValue;
    uchar gameDeveloperModeValue;
    uchar[9] playerCDAndVersionValue;
    uchar difficultyValue;
    uchar[9] playerTeamValue;
};
struct RGE_Game_World {
    ulong world_time;
    ulong old_world_time;
    ulong world_time_delta;
    float timer;
    ulong old_time;
    float game_speed;
    uchar temp_pause;
    uchar game_state;
    uchar game_end_condition;
    long sound_update_index;
    long sprite_update_index;
    RGE_Map * map;
    short sound_num;
    RGE_Sound * * sounds;
    short sprite_num;
    RGE_Sprite * * sprites;
    short player_num;
    RGE_Player * * players;
    short master_player_num;
    RGE_Master_Player * * master_players;
    RGE_Effects * effects;
    short terrain_num;
    short terrain_size;
    float * * terrains;
    RGE_Command * commands;
    RGE_Scenario * scenario;
    short color_table_num;
    RGE_Color_Table * * color_tables;
    long next_object_id;
    long next_reusable_object_id;
    long scenario_object_id;
    uchar scenario_object_flag;
    uint random_seed;
    short curr_player;
    TSound_Driver * sound_driver;
    float world_time_delta_seconds;
    RGE_Static_Object * * objectsValue;
    int numberObjectsValue;
    int maxNumberObjectsValue;
    RGE_Static_Object * * negativeObjectsValue;
    int numberNegativeObjectsValue;
    int maxNumberNegativeObjectsValue;
    AIPlayBook * playbook;
    long campaign;
    long campaign_player;
    long campaign_scenario;
    int player_turn;
    ulong[9] player_time_delta;
    RGE_Object_List * reusable_static_objects;
    RGE_Object_List * reusable_animated_objects;
    RGE_Object_List * reusable_moving_objects;
    RGE_Object_List * reusable_action_objects;
    RGE_Object_List * reusable_combat_objects;
    RGE_Object_List * reusable_missile_objects;
    RGE_Object_List * reusable_doppleganger_objects;
    ulong maximumComputerPlayerUpdateTime;
    ulong availableComputerPlayerUpdateTime;
    int currentUpdateComputerPlayer;
    int difficultyLevelValue;
};
struct RGE_Info_Line {
    float clump_num;
    short percent_of_tiles_covered;
    short percent_updown;
    short min_elevation;
    short max_elevation;
    short terrain_type;
    short terrain_base;
    char obj_id;
};
struct RGE_Land_Data {
    long[4] map_edge_buffer;
    long map_edge_fade;
    long land_placement_edge;
    long base_terrain;
    long grown_land_percent;
    long id;
    long land_num;
    RGE_Land_Data_Entry * land;
};
struct RGE_Land_Data_Entry {
    long land_id;
    uchar terrain_type;
    long land_avoidance_tiles;
    long base_square_radius;
    uchar zone;
    uchar placement_type;
    long x;
    long y;
    uchar amount_of_land_used_percent;
    uchar by_player_flag;
    long radius;
    long fade;
    long clumpiness_factor;
};
struct RGE_Land_Info {
    RGE_Land_Info_Line[99] land;
    long land_num;
    uchar base_terrain;
    long wall_1_avoidance_line;
    long wall_2_avoidance_line;
    long wall_3_avoidance_line;
    long wall_4_avoidance_line;
    uchar wall_fade;
};
struct RGE_Land_Info_Line {
    long land_size;
    long terrain_type;
    long x;
    long y;
    long base_size;
    long area;
    uchar zone;
    long clumpiness_factor;
    long wall_1_avoidance_line;
    long wall_2_avoidance_line;
    long wall_3_avoidance_line;
    long wall_4_avoidance_line;
    uchar wall_fade;
};
struct RGE_Land_Point_Info_Line {
    long x;
    long y;
    long id;
    long player_id;
};
struct RGE_Lobby {
    void * HostHWND;
    IDirectPlayLobby * glpDPL;
    IDirectPlayLobby2 * glpDPL2;
    IDirectPlay2 * glpDP;
    DPLCONNECTION * glpdplConnection;
    uchar lobby_game;
    RGE_Comm_Error * Err;
};
struct RGE_Main_View {
    TPanel * map_view;
    ulong last_mouse_scroll_time;
    int mouse_scrolling;
    long mouse_last_x;
    long mouse_last_y;
    ulong last_key_scroll_time;
    int key_scrolling;
    RGE_Player * save_player;
};
struct RGE_Map {
    RGE_Tile * map;
    long map_width;
    long map_height;
    long world_width;
    long world_height;
    RGE_Tile_Size[19] tilesizes;
    RGE_Tile_Set[32] terrain_types;
    RGE_Border_Set[16] border_types;
    RGE_Tile * * map_row_offset;
    short num_terrain;
    short num_borders;
    short max_terrain;
    short tile_width;
    short tile_height;
    short tile_half_height;
    short tile_half_width;
    short elev_height;
    short cur_row;
    short cur_col;
    short block_beg_row;
    short block_end_row;
    short block_beg_col;
    short block_end_col;
    uchar any_frame_change;
    uchar * search_map;
    uchar * * search_map_rows;
    uchar map_visible_flag;
    uchar fog_flag;
    RGE_RMM_Database_Controller * random_map;
    RGE_Game_World * game_world;
    RGE_Zone_Map_List * map_zones;
    RGE_Unified_Visible_Map * unified_vis_map;
    Visible_Unit_Manager * unit_manager;
};
struct RGE_Map_Data {
    long map_num;
    RGE_Map_Data_Entry * maps;
};
struct RGE_Map_Data_Entry {
    long map_id;
    RGE_Land_Data land_info;
    RGE_Terrain_Data terrain_info;
    RGE_Object_Data object_info;
    RGE_Elevation_Data elevation_info;
};
struct RGE_Map_Gen_Info {
    short base_terrain;
    RGE_Info_Line land;
    RGE_Info_Line[20] elevation;
    short elevation_num;
    RGE_Info_Line[20] terrain;
    short terrain_num;
    RGE_Info_Line[20] objects;
    short objects_num;
    short player_num;
    short[9] player_x;
    short[9] player_y;
    short[9] player_connect;
    short[9] player_base_land;
    short space_between_islands_or_edge;
};
struct RGE_Map_Image_Line {
    short tile_row;
    short start_x;
    short line_len;
};
struct RGE_Map_Tile_Row {
    short image_line;
    uchar draw;
    short row_len;
    float col_step;
    float col_extra;
    short map_col;
    short map_row;
    short draw_wid;
    float draw_step;
    short num_tiles;
    float ratio;
};
struct RGE_Master_Action_Object {
    RGE_Task_List * tasks;
    short default_task;
    float search_radius;
    float work_rate;
    short drop_site;
    short backup_drop_site;
    uchar task_by_group;
    RGE_Sound * command_sound;
    RGE_Sound * move_sound;
    uchar run_pattern;
};
struct RGE_Master_Animated_Object {
    float speed;
};
struct RGE_Master_Combat_Object {
    RGE_Sprite * fight_sprite;
    uchar base_armor;
    short armor_num;
    RGE_Armor_Weapon_Info * armor;
    short weapon_num;
    RGE_Armor_Weapon_Info * weapon;
    short defense_terrain_bonus;
    float weapon_range;
    float area_effect_range;
    uchar area_effect_level;
    float speed_of_attack;
    short missile_id;
    short base_hit_chance;
    uchar break_off_combat;
    short fire_missile_at_frame;
    float weapon_offset_x;
    float weapon_offset_y;
    float weapon_offset_z;
    float minimum_weapon_range;
    short orig_armor;
    short orig_weapon;
    float orig_weapon_range;
    float orig_speed_of_attack;
};
struct RGE_Master_Doppleganger_Object {
};
struct RGE_Master_Missile_Object {
    uchar missile_type;
    uchar targetting_type;
    uchar missile_hit_info;
    uchar missile_die_info;
    uchar area_effect_specials;
    float ballistics_ratio;
};
struct RGE_Master_Moving_Object {
    RGE_Sprite * move_sprite;
    RGE_Sprite * run_sprite;
    float turn_speed;
    uchar size_class;
    short obj_trail_id;
    uchar obj_trail_options;
    float obj_trail_spacing;
    uchar move_algorithem;
};
struct RGE_Master_Player {
    char[20] name;
    short master_object_num;
    RGE_Master_Static_Object * * master_objects;
    short attribute_num;
    float * attributes;
    uchar culture;
    uchar type;
    short tribe_effect;
};
struct RGE_Master_Static_Object {
    uchar master_type;
    char * name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    RGE_Sprite * sprite;
    RGE_Sprite * death_sprite;
    RGE_Sprite * undead_sprite;
    uchar undead_flag;
    short hp;
    float los;
    uchar obj_max;
    float radius_x;
    float radius_y;
    float radius_z;
    RGE_Sound * selected_sound;
    RGE_Sound * created_sound;
    RGE_Sound * death_sound;
    short death_spawn_obj_id;
    uchar sort_number;
    uchar can_be_built_on;
    short button_pict;
    uchar hide_in_scenario_editor;
    short portrait_pict;
    uchar available;
    short tile_req1;
    short tile_req2;
    short center_tile_req1;
    short center_tile_req2;
    float construction_radius_x;
    float construction_radius_y;
    uchar elevation_flag;
    uchar fog_flag;
    short terrain;
    uchar movement_type;
    short[3] attribute_type_held;
    float[3] attribute_amount_held;
    short attribute_max_amount;
    float attribute_rot;
    float multiple_attribute_mod;
    uchar[3] attribute_flag;
    uchar area_effect_object_level;
    uchar combat_level;
    uchar select_level;
    uchar map_draw_level;
    uchar unit_level;
    uchar map_color;
    uchar attack_reaction;
    uchar convert_terrain_flag;
    uchar damage_sprite_num;
    RGE_Damage_Sprite_Info * damage_sprites;
    long help_string_id;
    long help_page_id;
    long hotkey_id;
    uchar recyclable;
    uchar track_as_resource;
    uchar create_doppleganger_on_death;
    uchar resource_group;
    uchar draw_flag;
    uchar draw_color;
    float outline_radius_x;
    float outline_radius_y;
    float outline_radius_z;
};
struct RGE_Missile_Object {
    float max_range;
};
struct RGE_Moving_Object {
    float trail_remainder;
    float velocity_x;
    float velocity_y;
    float velocity_z;
    float angle;
    float turn_towards_time;
    Path pathValue;
    Path exceptionPathValue;
    Waypoint startValue;
    Waypoint goalValue;
    float turnTimer;
    float collisionAvoidanceDistance;
    float actionRange;
    int targetIDValue;
    float targetRadiusX;
    float targetRadiusY;
    int continueCounter;
    int rangeStatusValue;
    int currentTerrainException1;
    int currentTerrainException2;
    uchar storePathInExceptionPath;
    uchar waitingToMoveValue;
    uchar numberWaitDelays;
    XYPoint minInitialPointValue;
    XYPoint maxInitialPointValue;
    XYZBYTEPoint * userDefinedWaypoints;
    int numberUserDefinedWaypointsValue;
    int maxUserDefinedWaypointsValue;
    uchar finalUserDefinedWaypoint;
    float closestDistanceToWaypoint;
    uchar lastFacet;
    uchar lastFacet2;
};
struct RGE_Obj_Info {
    long id;
};
struct RGE_Object_Data {
    long object_num;
    RGE_Object_Data_Entry * objects;
};
struct RGE_Object_Data_Entry {
    long obj_id;
    long terrain;
    uchar group_flag;
    uchar scale_flag;
    long object_number_per_group;
    long object_number_varience;
    long number_of_groups;
    long group_area;
    long player_id;
    long land_id;
    long land_inner_radius;
    long land_outer_radius;
};
struct RGE_Object_Info {
    RGE_Object_Info_Line[99] objects;
    long object_num;
    RGE_Land_Point_Info_Line[99] lands;
    long land_num;
};
struct RGE_Object_Info_Line {
    long obj_id;
    long terrain;
    uchar group_flag;
    uchar scale_flag;
    long object_number_per_group;
    long object_number_varience;
    long number_of_groups;
    long group_area;
    long player_id;
    long land_id;
    long land_inner_radius;
    long land_outer_radius;
    long object_exclusion_zone;
};
struct RGE_Object_List {
    RGE_Object_Node * list;
    short number_of_objects;
};
struct RGE_Object_Node {
    RGE_Static_Object * node;
    RGE_Object_Node * next;
    RGE_Object_Node * prev;
    uchar centered;
};
struct RGE_Panel_Time {
    void * font;
    long game_time;
    long last_game_time;
    long old_time;
    long real_time;
};
struct RGE_Panel_Tool_Box {
    TScreenPanel * screen_panel;
    RGE_View * view;
    RGE_Diamond_Map * map;
    TButtonPanel * game_mode_button;
    TButtonPanel * object_mode_button;
    TButtonPanel * delete_mode_button;
    TButtonPanel * move_mode_button;
    TButtonPanel * terrain_mode_button;
    TButtonPanel * elevation_mode_button;
    TButtonPanel * command_button;
    TPanel * dialog;
};
struct RGE_Person_Info {
    char[255] name;
    long current_campaign;
    long campaign_info_num;
    RGE_Campaign_Info * * campaign_info;
    long campaign_num;
    RGE_Campaign * * campaigns;
};
struct RGE_Pick_Info {
    float x;
    float y;
    short scr_x;
    short scr_y;
    RGE_Static_Object * object;
    RGE_Tile * tile;
};
struct RGE_Pick_Obj_Info {
    int object_id;
    short confidence;
    short draw_level;
    short draw_x;
    short draw_y;
};
struct RGE_Picture_List {
    short picture_num;
    RGE_Sprite * sprite;
    short offset_x;
    short offset_y;
    short facet;
};
struct RGE_Player {
    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;
    long checksum;
    long position_checksum;
    long action_checksum;
    uchar checksum_created_this_update;
    short master_object_num;
    RGE_Master_Static_Object * * master_objects;
    RGE_Object_List * objects;
    RGE_Object_List * sleeping_objects;
    RGE_Object_List * doppleganger_objects;
    RGE_Victory_Conditions * victory_conditions;
    RGE_Visible_Map * visible;
    RGE_Game_World * world;
    RGE_Doppleganger_Creator * doppleganger_creator;
    char * name;
    uchar type;
    short id;
    short attribute_num;
    float * attributes;
    uchar culture;
    RGE_Tile_List tile_list;
    RGE_Tile_List diam_tile_list;
    uchar game_status;
    uchar resigned;
    uchar * relations;
    int[9] unitDiplomacy;
    int[9] mutualAlly;
    ulong mutualExploredMask;
    ulong mutualVisibleMask;
    ulong nonMutualVisibleMask;
    ulong[9] RemoveVisibleBits;
    int allied_LOS_Enable;
    uchar allied_victory;
    uchar master_player_id;
    RGE_Color_Table * color_table;
    long tribe_effect;
    Visible_Resource_Manager * VR_List;
    float view_x;
    float view_y;
    short map_x;
    short map_y;
    short selected_start_col;
    short selected_start_row;
    short selected_end_col;
    short selected_end_row;
    short replacement_terrain;
    short replacement_overlay;
    short replacement_overlay_shape;
    RGE_Static_Object * selected_obj;
    RGE_Static_Object *[25] sel_list;
    ulong sel_object_properties;
    short sel_count;
    uchar[127] groups_used;
};
struct RGE_Player_Info {
    char[9][65] name;
    char[9] type;
    char[9] tribe;
    short[9] color;
    long[9] player_id_hash;
    short player_num;
    char * scenario;
    RGE_Map_Gen_Info * map_info;
    short map_type;
    short map_width;
    short map_height;
    short ai_info;
    uchar campaign;
};
struct RGE_Prog_Info {
    char[101] prog_name;
    char[21] prog_version;
    char[121] prog_title;
    char[261] world_db_file;
    char[261] game_data_file;
    char[261] vol_name;
    ulong vol_ser_num;
    int verify_cd;
    int max_players_per_cd;
    void * instance;
    void * prev_instance;
    char[256] registry_key;
    char[256] cmd_line;
    int show_wnd_flag;
    char[41] icon_name;
    char[41] menu_name;
    char[261] pal_file;
    char[261] cursor_file;
    int max_players;
    int check_expiration;
    short expire_month;
    short expire_day;
    short expire_year;
    ulong update_interval;
    int check_multi_copies;
    int skip_startup;
    int full_screen;
    int fixed_window_size;
    int use_dir_draw;
    int use_sys_mem;
    int use_music;
    int use_sound;
    int use_cd_audio;
    int use_ima;
    int use_midi;
    int use_wave_music;
    int fast_view;
    int auto_scroll;
    long mouse_scroll_edge;
    ulong mouse_scroll_interval;
    float mouse_scroll_max_dist;
    ulong key_scroll_interval;
    float key_scroll_max_dist;
    float key_scroll_object_move;
    short interface_style;
    long main_wid;
    long main_hgt;
    _GUID game_guid;
    _GUID zone_guid;
    char[261] data_dir;
    char[261] graphics_dir;
    char[261] save_dir;
    char[261] scenario_dir;
    char[261] campaign_dir;
    char[261] sounds_dir;
    char[261] resource_dir;
    char[261] ai_dir;
    char[261] avi_dir;
};
struct RGE_Random_Map_Module {
    RGE_Random_Map_Module * parent;
    RGE_Random_Map_Module_List * list;
    RGE_Map * map;
    RGE_Tile * * map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    uchar * search_map;
    uchar * * search_map_rows;
    Map_Stack * stack_array;
    Map_Stack * * stack_offsets;
};
struct RGE_Random_Map_Module_List {
    RGE_Random_Map_Module * module;
    RGE_Random_Map_Module_List * next;
};
struct RGE_RMM_Cliffs_Generator {
    RGE_Cliffs_Info info;
    Map_Stack valid_cliff_sites;
};
struct RGE_RMM_Controller {
};
struct RGE_RMM_Database_Controller {
    RGE_Game_World * world;
    long map_type;
    long number_of_players;
    RGE_Land_Info land_info;
    RGE_Terrain_Info terrain_info;
    RGE_Object_Info object_info;
    RGE_Elevation_Info elevation_info;
    RGE_Map_Data map_info;
};
struct RGE_RMM_Elevation_Generator {
    RGE_Elevation_Info info;
};
struct RGE_RMM_Land_Generator {
    RGE_Land_Info info;
};
struct RGE_RMM_Object_Generator {
    RGE_Game_World * world;
    RGE_Object_Info info;
    uchar[32] terrain_table;
    uchar add_terrain;
};
struct RGE_RMM_Shallows_Generator {
    RGE_Shallows_Info info;
};
struct RGE_RMM_Terrain_Generator {
    RGE_Terrain_Info info;
    RGE_Zone_Map * map_zone;
};
struct RGE_Scenario {
    RGE_Timeline * time_line;
    RGE_Game_World * world;
    uchar victory_conquest;
    PlayerName[16] player_name;
    char * scenario_name;
    char * description;
    char * hints;
    char * win_message;
    char * loss_message;
    char * historicle_notes;
    char[224] TempText1;
    char[224] TempText2;
    char[224] TempText3;
    char *[16] BuildList;
    char *[16] CityPlan;
    char *[16] AiRules;
    uchar *[16] BuildListFile;
    uchar *[16] CityPlanFile;
    uchar *[16] AiRulesFile;
    int[16] BuildListFileSize;
    int[16] CityPlanFileSize;
    int[16] AiRulesFileSize;
    char[224] Cine_PreGame;
    char[224] Cine_Victory;
    char[224] Cine_Loss;
    char[224] Mission_Bmp;
    float Version;
    int[16] PlayerPosture;
    int[16] PlType;
    int[16] PlCivilization;
    int[16] PlActive;
    TPicture * mission_picture;
};
struct RGE_Scenario_File_Entry {
    long time;
    RGE_Scenario_Header * scenario_header;
    char[260] name;
};
struct RGE_Scenario_File_Info {
    char[260] filename;
    long scenario_num;
    RGE_Scenario_File_Entry * scenarios;
};
struct RGE_Scenario_Header {
    int error_code;
    long version;
    ulong checksum;
    char * description;
};
struct RGE_Scenario_Info {
    uchar scenario_status;
};
struct RGE_Scenario_Offset {
    long size;
    long offset;
    char[255] name;
    char[255] file_name;
};
struct RGE_Shallows_Info {
    RGE_Shallows_Info_Line[99] shallows;
    long shallows_num;
};
struct RGE_Shallows_Info_Line {
    long x;
    long y;
};
struct RGE_Sound {
    short play_at_update_count;
    short sound_num;
    RGE_Sound_Info * sounds;
    ulong cache_time;
    short id;
};
struct RGE_Sound_Info {
    char[13] name;
    long resource_id;
    short percent;
    TDigital * digital_sound;
    uchar loaded;
    ulong time;
};
struct RGE_Sound_List {
    RGE_Sound *[3] sound;
    short[3] frame;
};
struct RGE_SPick_Info {
    int object_id;
    short confidence;
    short draw_level;
    short draw_x;
    short draw_y;
    RGE_SPick_Info * next;
    RGE_SPick_Info * prev;
};
struct RGE_Sprite {
    char[13] pict_name;
    long resource_id;
    uchar loaded;
    RGE_Color_Table * * color_tables;
    TShape * shape;
    long last_time;
    long delta_time;
    uchar color_flag;
    uchar draw_level;
    short color_table;
    uchar transparent_picking_flag;
    short box_x1;
    short box_y1;
    short box_x2;
    short box_y2;
    short draw_list_num;
    RGE_Picture_List * draw_list;
    RGE_Sound * main_sound;
    uchar micro_man_sound;
    RGE_Sound_List * sound_list;
    char[21] name;
    short frame_num;
    short facet_num;
    float base_speed;
    float duration;
    float pause_between_loops;
    uchar flag;
    short id;
    uchar mirror_flag;
};
struct RGE_Static_Object {
    long id;
    RGE_Master_Static_Object * master_obj;
    RGE_Player * owner;
    RGE_Sprite * sprite;
    RGE_Sprite * old_sprite;
    RGE_Active_Sprite_List * sprite_list;
    RGE_Tile * tile;
    RGE_Static_Object * inside_obj;
    RGE_Object_List * objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    uchar curr_damage_percent;
    uchar facet;
    uchar selected;
    uchar selected_group;
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    uchar object_state;
    uchar sleep_flag;
    uchar dopple_flag;
    uchar goto_sleep_flag;
    short attribute_type_held;
    uchar type;
    uchar worker_num;
    RGE_Object_Node * player_object_node;
    ManagedArray<int> pathingGroupMembers;
    ManagedArray<int> groupMembers;
    UnitAIModule * unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    uchar inObstructionMapValue;
    uchar lastInObstructionMapValue;
    uchar underAttackValue;
};
struct RGE_Task {
    short task_type;
    short id;
    uchar is_default;
    short action_type;
    short object_group;
    short object_id;
    uchar combat_level;
    uchar combat_level_flag;
    short terrain_id;
    uchar owner_type;
    uchar holding_attr;
    uchar state_building;
    short attribute_type;
    short attribute_type2;
    short attribute_type3;
    short attribute_type4;
    float work_val1;
    float work_val2;
    float work_range;
    uchar search_flag;
    float search_wait_time;
    short work_flag;
    short work_flag2;
    RGE_Sprite * move_sprite;
    RGE_Sprite * work_sprite;
    RGE_Sprite * work_sprite2;
    RGE_Sprite * carry_sprite;
    RGE_Sound * work_sound;
    RGE_Sound * work_sound2;
};
struct RGE_Task_List {
    RGE_Task * * list;
    short list_num;
};
struct RGE_Terrain_Data {
    long terrain_num;
    RGE_Terrain_Data_Entry * terrain;
};
struct RGE_Terrain_Data_Entry {
    long terrain_percent;
    long terrain_type;
    long clumps;
    long spacing;
    long base_terrain_type;
    long clumpiness_factor;
};
struct RGE_Terrain_Hot_Spots {
    long x;
    long y;
    long radius;
    long fade;
};
struct RGE_Terrain_Info {
    RGE_Terrain_Info_Line[99] terrain;
    long terrain_num;
    RGE_Terrain_Hot_Spots[99] hot_spots;
    long hot_spot_num;
};
struct RGE_Terrain_Info_Line {
    long terrain_size;
    long terrain_generated;
    long terrain_type;
    long clumps;
    long spacing;
    long base_terrain_type;
    long clumpiness_factor;
    long avoid_hot_spots;
};
struct RGE_Tile {
    short screen_xpos;
    short screen_ypos;
    uchar tile_type;
    uchar:5 terrain_type;
    uchar:3 height;
    uchar:4 border_type;
    uchar:4 border_shape;
    uchar last_drawn_as;
    uchar last_drawn_shape;
    uchar draw_as;
    uchar draw_attribute;
    uchar last_drawn_shape2;
    RGE_Object_List objects;
};
struct RGE_Tile_List {
    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    RGE_Tile_List_Node * list;
};
struct RGE_Tile_List_Node {
    int col;
    int row;
};
struct RGE_Tile_Set {
    uchar loaded;
    uchar random;
    char[13] name;
    char[13] pict_name;
    long resource_id;
    TShape * shape;
    RGE_Sound * sound;
    uchar map_hi_color;
    uchar map_med_color;
    uchar map_low_color;
    uchar map_lt_cliff_color;
    uchar map_rt_cliff_color;
    uchar passable_terrain;
    uchar impassable_terrain;
    uchar is_animated;
    short animation_frames;
    short pause_frames;
    float interval;
    float pause_between_loops;
    short frame;
    short draw_frame;
    float animate_last;
    uchar frame_changed;
    uchar drawn;
    RGE_TOB_Picts[19] tiles;
    short terrain_to_draw;
    short rows;
    short cols;
    short[32] borders;
    short[30] obj_types;
    short[30] obj_density;
    uchar[30] obj_placement_flag;
    short num_obj_type;
};
struct RGE_Tile_Size {
    short width;
    short height;
    short y_delta;
};
struct RGE_Time_Entry {
    float time;
    uchar command;
    short obj_type;
    uchar player;
    float x;
    float y;
    float z;
    short task;
    RGE_Static_Object * this_obj;
    short this_obj_id;
    RGE_Static_Object * target_obj;
    short target_obj_id;
    RGE_Time_Entry * next;
};
struct RGE_Timeline {
    RGE_Game_World * world;
    RGE_Time_Entry * time_list;
    short list_num;
    short avail_id;
    float old_time;
};
struct RGE_TimeSinceLastCall {
    char[255] TBuff;
    ulong lowTSLC;
    ulong highTSLC;
    ulong TSLC;
    ulong[101] aTSLC;
    int Offset;
    ulong LastCall;
    ulong FirstCall;
    ulong Now;
    ulong cps;
};
struct RGE_Timing_Info {
    ulong accum_time;
    ulong last_time;
    ulong start_time;
    int include_in_total;
    int is_summary;
    ulong last_single_time;
    ulong max_time;
    ulong last_max_time;
};
struct RGE_TOB_Picts {
    short count;
    short animations;
    short shape_index;
};
struct RGE_Unified_Visible_Map {
    int mapWidth;
    int mapHeight;
    ulong * UnifiedVisibleMap;
};
struct RGE_Victory_Conditions {
    RGE_Victory_Entry * victory_list;
    long list_num;
    RGE_Player * player;
    uchar victory;
    RGE_Victory_Point_Entry * victory_point_list;
    long point_list_num;
    long tot_victory_points;
};
struct RGE_Victory_Entry {
    uchar command;
    long obj_type;
    RGE_Player * target_player;
    float x0;
    float y0;
    float x1;
    float y1;
    long number;
    long count;
    RGE_Static_Object * this_obj;
    RGE_Static_Object * target_obj;
    uchar victory_group;
    uchar ally_flag;
    uchar state;
    uchar checked_flag;
    RGE_Victory_Entry * next;
};
struct RGE_Victory_Point_Entry {
    uchar command;
    uchar state;
    uchar id;
    uchar group;
    long attribute;
    long amount;
    long points;
    long curr_points;
    float curr_attribute_amount;
    RGE_Victory_Point_Entry * next;
};
struct RGE_View {
    TDrawArea * cur_render_area;
    int calc_draw_count;
    RGE_Game_World * world;
    RGE_Player * player;
    RGE_Map * map;
    short tile_wid;
    short tile_hgt;
    short tile_half_wid;
    short tile_half_hgt;
    short elev_hgt;
    short render_rect_wid;
    short render_rect_hgt;
    short max_col_num;
    short max_row_num;
    short center_scr_col;
    short center_scr_row;
    short center_scr_col_offset;
    short center_scr_row_offset;
    short center_map_col;
    short center_map_row;
    short start_scr_col;
    short start_scr_row;
    short start_map_col;
    short start_map_row;
    int map_scr_x_offset;
    int map_scr_y_offset;
    float last_view_x;
    float last_view_y;
    uchar function_mode;
    uchar function_parm;
    uchar render_terrain_mode;
    long sel_col1;
    long sel_row1;
    long sel_col2;
    long sel_row2;
    short save_paint_terrain;
    void * white_pen;
    void * red_pen;
    void * hollow_brush;
    TShape * border_line_shape;
    uchar scroll_action;
    long mouse_last_x;
    long mouse_last_y;
    RGE_Static_Object * movable_object;
    TSpan_List_Manager * Terrain_Clip_Mask;
    TSpan_List_Manager * Terrain_Fog_Clip_Mask;
    TSpan_List_Manager * Master_Clip_Mask;
    Tile_FogEdge_Table * * Tile_Edge_Tables;
    Tile_BlackEdge_Table * * Black_Edge_Tables;
    tagRECT OverlaidPanel;
    int OverlaidPanelActive;
    uchar[256] EdgeNumber;
    int Limited_Render_Rect;
    int Use_Rect2;
    tagRECT Render_Rect1;
    tagRECT Render_Rect2;
    void * * Float_Scroll_Offsets;
    int Float_Scroll_Offsets_Sz;
    int Float_X_Delta;
    int Float_Y_Delta;
    int Queued_Blits;
    Blit_Queue_Entry * Blit_Queue;
    int Blit_Queue_Size;
    int Blt_Queue_Allocated;
    int Current_Blit;
    int Blit_Offset_X;
    int Blit_Offset_Y;
    long real_old_map_col;
    long real_old_map_row;
    RGE_SPick_Info *[5] pick_lists;
    int[5] pick_list_size;
    TDrawArea * save_area1;
    uchar * LastRenderBits;
    void * * RenderOffsets;
    int LastRenderSize;
    DClipInfo_List * prior_objs;
    DClipInfo_List * futur_objs;
    int UC_ObjectTouched;
    int UC_TouchedObj;
    ulong UC_StartTime;
    ulong UC_ElapsedTime;
    TMessagePanel * message_panel;
    Ov_Sprite_Draw_Rec * extra_sprites;
    DisplaySelectedObjRec * DispSel_List;
    int DispSel_List_Size;
    int DispSel_List_Max;
};
struct RGE_Visible_Map {
    uchar * * map_offsets;
    RGE_Game_World * world;
    RGE_Player * player;
    RGE_Map * map;
    uchar * visible_map;
    int widthValue;
    int heightValue;
    int numberTilesExploredValue;
    int numberTotalTilesValue;
    ulong PlayerVisibleMaskValue;
    ulong PlayerVisibleMaskInvertValue;
    ulong PlayerExploredMaskValue;
    ulong PlayerExploredMaskInvertValue;
    ulong input_csum;
};
struct RGE_Zone_Map {
    int[257] numberTilesInZoneValue;
    uchar * zone_map;
    uchar * * zone_map_rows;
    uchar[257] zone_info;
    float * terrain_passability_rules;
    long terrain_passability_rules_num;
    RGE_Map * map;
};
struct RGE_Zone_Map_List {
    RGE_Zone_Map * * zone_maps;
    long zone_map_num;
    RGE_Map * map;
};
struct SEs {
    char[255] Name;
    char[255] Password;
    _GUID AppGUID;
    _GUID SessGUID;
    ulong CurrentPlayers;
    ulong MaxPlayers;
    ulong User1;
    ulong User2;
    ulong User3;
    ulong User4;
};
struct Shape_File_Header {
    long version;
    long shape_num;
};
struct Shape_Header {
    long bounds;
    long origin;
    long xmin;
    long ymin;
    long xmax;
    long ymax;
};
struct Shape_Info {
    ulong Shape_Data_Offsets;
    ulong Shape_Outline_Offset;
    long Reserved1;
    long Reserved2;
    long Width;
    long Height;
    long Hotspot_X;
    long Hotspot_Y;
};
struct Shape_Offsets {
    long shape;
    long palette;
};
struct SLhape_File_Header {
    char[4] Version;
    long Num_Shapes;
    char[24] Comment;
};
struct SNDOBJ {
    uchar * pbWaveData;
    ulong cbWaveSize;
    int iAlloc;
    int iCurrent;
    IDirectSoundBuffer *[1] Buffers;
};
struct SP_Victory_Info {
    int ObjType;
    int AllFlag;
    int PlayerID;
    int DestObjID;
    float x1;
    float y1;
    float x2;
    float y2;
    int VictoryType;
    int Amount;
    int AttribType;
    int obj_ID;
    int dest_obj_ID;
    RGE_Static_Object * obj;
    RGE_Static_Object * dest_obj;
};
struct Special_Events {
    long time_slice;
    long X_line_pos;
    long Y_line_pos;
    long intermediate_y_line_segment;
    uchar player_id;
    uchar player_color;
    uchar event;
    long pop_total;
    long interger_value_1;
    long interger_value_2;
    long start_x;
    long start_y;
    long start_txt_x1;
    long start_txt_y1;
    long start_txt_x2;
    long start_txt_y2;
    int text_length1;
    char[50] text1;
    int text_length2;
    char[50] text2;
    int icon_flag;
    Special_Events * next;
};
struct SPs {
    char[80] Name;
    _GUID * GUID;
    ulong MajVersion;
    ulong MinVersion;
    int Active;
};
struct StrategyAIModule {
};
struct streambuf {
    int _fAlloc;
    int _fUnbuf;
    int x_lastc;
    char * _base;
    char * _ebuf;
    char * _pbase;
    char * _pptr;
    char * _epptr;
    char * _eback;
    char * _gptr;
    char * _egptr;
};
struct StringFileInfo {
    word wLength;
    word wValueLength;
    word wType;
};
struct StringInfo {
    word wLength;
    word wValueLength;
    word wType;
};
struct StringTable {
    word wLength;
    word wValueLength;
    word wType;
};
struct T_Scenario {
    Player_Start_Info[16] player_info;
    Victory_StartInfo victory;
    SP_Victory_Info[16][12] sp_victory;
    Friendliness[16] Opponent;
    int[16] AlliedVictory;
    int victory_all_flag;
    int is_multi_player_flag;
    int which_player;
    int[16][20] DisabledTechnology;
    int[3] ScenarioOptions;
    int[16] PlayerAge;
    int mp_victory_type;
    int victory_score;
    int victory_time;
};
struct TacticalAIGroup {
    TacticalAIGroup * next;
    TacticalAIGroup * prev;
    int idValue;
    int inUseValue;
    int typeValue;
    int subTypeValue;
    int[40] unitsValue;
    int[40] unitsOriginalHitPointsValue;
    int numberUnitsValue;
    int desiredNumberUnitsValue;
    int commanderValue;
    int originalHitPointsValue;
    int originalUnitNumberValue;
    Waypoint locationValue;
    int actionValue;
    int targetValue;
    int targetTypeValue;
    Waypoint targetLocationValue;
    Waypoint gatherLocationValue;
    Waypoint retreatLocationValue;
    int priorityValue;
    int waitCodeValue;
    int assistGroupIDValue;
    int assistGroupTypeValue;
    ulong consecutiveIdleUnitCountValue;
    int playNumberValue;
    uchar numberAttackWaypointsValue;
    uchar currentAttackWaypointValue;
    Waypoint[15] attackWaypoints;
    uchar consecutiveGatherAttemptsValue;
    int numberObjectsToDestroyValue;
    int[20] objectsToDestroyValue;
    int objectsToDestroyOwnerValue;
    int objectsToDestroyCommanderZoneValue;
    ulong lastAttackRoundupTime;
    ulong lastAddedUnitTimeValue;
};
struct TacticalAIModule {
};
struct tagBITMAP {
    long bmType;
    long bmWidth;
    long bmHeight;
    long bmWidthBytes;
    ushort bmPlanes;
    ushort bmBitsPixel;
    void * bmBits;
};
struct tagBITMAPCOREHEADER {
    ulong bcSize;
    ushort bcWidth;
    ushort bcHeight;
    ushort bcPlanes;
    ushort bcBitCount;
};
struct tagBITMAPFILEHEADER {
    ushort bfType;
    ulong bfSize;
    ushort bfReserved1;
    ushort bfReserved2;
    ulong bfOffBits;
};
struct tagBITMAPINFOHEADER {
    ulong biSize;
    long biWidth;
    long biHeight;
    ushort biPlanes;
    ushort biBitCount;
    ulong biCompression;
    ulong biSizeImage;
    long biXPelsPerMeter;
    long biYPelsPerMeter;
    ulong biClrUsed;
    ulong biClrImportant;
};
struct tagLOGFONTA {
    long lfHeight;
    long lfWidth;
    long lfEscapement;
    long lfOrientation;
    long lfWeight;
    uchar lfItalic;
    uchar lfUnderline;
    uchar lfStrikeOut;
    uchar lfCharSet;
    uchar lfOutPrecision;
    uchar lfClipPrecision;
    uchar lfQuality;
    uchar lfPitchAndFamily;
    char[32] lfFaceName;
};
struct tagMCI_OPEN_PARMSA {
    ulong dwCallback;
    uint wDeviceID;
    char * lpstrDeviceType;
    char * lpstrElementName;
    char * lpstrAlias;
};
struct tagMCI_PLAY_PARMS {
    ulong dwCallback;
    ulong dwFrom;
    ulong dwTo;
};
struct tagMCI_SEEK_PARMS {
    ulong dwCallback;
    ulong dwTo;
};
struct tagMCI_SET_PARMS {
    ulong dwCallback;
    ulong dwTimeFormat;
    ulong dwAudio;
};
struct tagMCI_STATUS_PARMS {
    ulong dwCallback;
    ulong dwReturn;
    ulong dwItem;
    ulong dwTrack;
};
struct tagMIXERCONTROLA {
    ulong cbStruct;
    ulong dwControlID;
    ulong dwControlType;
    ulong fdwControl;
    ulong cMultipleItems;
    char[16] szShortName;
    char[64] szName;
    __unnamed Bounds;
    __unnamed Metrics;
};
struct tagMIXERLINEA {
    ulong cbStruct;
    ulong dwDestination;
    ulong dwSource;
    ulong dwLineID;
    ulong fdwLine;
    ulong dwUser;
    ulong dwComponentType;
    ulong cChannels;
    ulong cConnections;
    ulong cControls;
    char[16] szShortName;
    char[64] szName;
    __unnamed Target;
};
struct tagMIXERLINECONTROLSA {
    ulong cbStruct;
    ulong dwLineID;
    ulong cControls;
    ulong cbmxctrl;
    tagMIXERCONTROLA * pamxctrl;
};
struct tagMSG {
    void * hwnd;
    uint message;
    uint wParam;
    long lParam;
    ulong time;
    tagPOINT pt;
};
struct tagPALETTEENTRY {
    uchar peRed;
    uchar peGreen;
    uchar peBlue;
    uchar peFlags;
};
struct tagPOINT {
    long x;
    long y;
};
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};
struct tagRGBQUAD {
    uchar rgbBlue;
    uchar rgbGreen;
    uchar rgbRed;
    uchar rgbReserved;
};
struct tagSIZE {
    long cx;
    long cy;
};
struct tagTEXTMETRICA {
    long tmHeight;
    long tmAscent;
    long tmDescent;
    long tmInternalLeading;
    long tmExternalLeading;
    long tmAveCharWidth;
    long tmMaxCharWidth;
    long tmWeight;
    long tmOverhang;
    long tmDigitizedAspectX;
    long tmDigitizedAspectY;
    uchar tmFirstChar;
    uchar tmLastChar;
    uchar tmDefaultChar;
    uchar tmBreakChar;
    uchar tmItalic;
    uchar tmUnderlined;
    uchar tmStruckOut;
    uchar tmPitchAndFamily;
    uchar tmCharSet;
};
struct tagVS_FIXEDFILEINFO {
    ulong dwSignature;
    ulong dwStrucVersion;
    ulong dwFileVersionMS;
    ulong dwFileVersionLS;
    ulong dwProductVersionMS;
    ulong dwProductVersionLS;
    ulong dwFileFlagsMask;
    ulong dwFileFlags;
    ulong dwFileOS;
    ulong dwFileType;
    ulong dwFileSubtype;
    ulong dwFileDateMS;
    ulong dwFileDateLS;
};
struct tagWAVEINFOCA {
    tWAVEFORMATEX * pwfx;
    void * hmmio;
    _MMCKINFO mmck;
    _MMCKINFO mmckInRIFF;
    IDirectSoundBuffer * lpDSBStreamBuffer;
    ulong dwBufferSize;
    ulong dwBufferSegSize;
    ulong dwNextWriteOffset;
    ulong dwPlayLast;
    ulong dwProgress;
    int bDonePlaying;
    int bLoopFile;
    int bFoundEnd;
    int nRemainingSegments;
};
struct tagWNDCLASSA {
    uint style;
    void * lpfnWndProc;
    int cbClsExtra;
    int cbWndExtra;
    void * hInstance;
    void * hIcon;
    void * hCursor;
    void * hbrBackground;
    char * lpszMenuName;
    char * lpszClassName;
};
struct TButtonPanel {
    long[9] id;
    long[9] id2;
    ButtonType buttonTypeValue;
    DrawType drawTypeValue;
    NotifyType notifyTypeValue;
    TDigital * sound;
    TShape *[9] pic;
    short[9] pic_index;
    int auto_pic_pos;
    long pic_x;
    long pic_y;
    int all_hot;
    int draw_reverse;
    char *[9] text1;
    char *[9] text2;
    long text_x;
    long text_y;
    void * font;
    long font_wid;
    long font_hgt;
    short num_states;
    short cur_state;
    int is_down;
    TButtonPanel * * radio_buttons;
    short num_radio_buttons;
    ulong button_down_time;
    ulong[9] text_color1;
    ulong[9] text_color2;
    ulong[9] highlight_text_color1;
    ulong[9] highlight_text_color2;
    long hotkey;
    int hotkey_shift;
    int bevel_type;
    uchar bevel_color1;
    uchar bevel_color2;
    uchar bevel_color3;
    uchar bevel_color4;
    uchar bevel_color5;
    uchar bevel_color6;
    long key_down;
    int disabled;
    int sound_number;
};
struct TChat {
    void * HostWnd;
    int[10] chatGroupPlayers;
    char *[51] Chat;
    int CurrentMsgNo;
    TTaunt * taunt;
};
struct TCommunications_Handler {
    int OptionsChanged;
    char * OptionsData;
    int Steps;
    ulong TickStart;
    ulong TickCount;
    ulong TimeSinceLastCall;
    TChat * Chat;
    int MeHost;
    int HaveHostInit;
    char[4001] InCommBuff;
    char[257] TBuff;
    ulong current_turn;
    ulong next_command_turn;
    uint sequence;
    long WaitOnPlayer;
    ulong TurnSpeedMsec;
    ulong AcknowledgeAfterMsec;
    uint Me;
    int Multiplayer;
    int OutOfSyncFlag;
    ulong dwStopTime;
    float lastRXDataRate;
    float lastTXDataRate;
    char[129] MyFriendlyName;
    char[129] MyFormalName;
    char[129] MyGameTitle;
    ulong CurrentPlayers;
    int previous_last_world_random;
    int last_world_random;
    int StepMode;
    ulong turnstart;
    ulong lastcalltick;
    ulong mselapsed;
    int AvgTurnTime;
    int SkipFrames;
    int PauseChangePending;
    ulong CommunicationsVersionCode;
    int ShuttingDown;
    ulong ReturnElapsed;
    ulong ReturnRXPacketSize;
    ulong ReturnTXPacketSize;
    ulong RXPacketLength;
    ulong RXPacketLengthHigh;
    ulong TXPacketLength;
    ulong TXPacketLengthHigh;
    NAME * FriendlyName;
    NAME * FormalName;
    ulong LastTimeoutMessageTime;
    COMMSTATUS CommunicationsStatus;
    ushort MaxGamePlayers;
    _GUID ServiceGUID;
    _GUID ApplicationGUID;
    _GUID SessionGUID;
    void * HostHWND;
    int LobbyLaunched;
    ulong MaxReceiveLatency;
    _GUID NullGUID;
    ulong ResendAcknowledgements;
    ulong ResentToOther;
    ulong DroppedPacketCount;
    ulong RXPackets;
    ulong TXPackets;
    int IAmLagging;
    ulong ServiceTimeout;
    ulong[10] LastPlayerCommunication;
    ulong[10] LastPlayerWarning;
    ulong[10] LastTXPing;
    ulong[10] PlayerStopTurn;
    uint[10] LastSerialRequestedTX;
    ulong[10] LastRequestHonoredTX;
    uint[10] LastSerialRepliedTX;
    ulong[10] LastRequestRepliedTX;
    ulong dwFlags;
    ulong dwMaxBufferSize;
    ulong dwMaxQueueSize;
    ulong dwMaxPlayers;
    ulong dwHundredBaud;
    ulong dwLatency;
    int[10] Kicked;
    RGE_Communications_Queue * InQ;
    RGE_Communications_Queue * OutQ;
    RGE_Lobby * Lobby;
    RGE_TimeSinceLastCall * tslc;
    RGE_Communications_Speed * Speed;
    RGE_Communications_Synchronize * Sync;
    RGE_Communications_Addresses * Addresses;
    RGE_Comm_Error * Err;
    uint GTDSerialNo;
    uint HighResendStore;
    uint[10] DestMap;
    uchar RGE_Guaranteed_Delivery;
    int IntentionallyDropPackets;
    uint WaitingForAck;
    RESENDER * Resend;
    HOLDER * OnHold;
    uint[10] PlayerHighSerialNumber;
    COMMPLAYEROPTIONS PlayerOptions;
    ulong[10] LastTurnAck;
    uint HoldCount;
    int[10] WasKicked;
};
struct TCommunications_Services {
    SPs[100] Service;
    int ServiceCount;
};
struct TCommunications_Sessions {
    int SessionCount;
    SEs[501] Session;
    _GUID glpGuid;
    IDirectPlay2 * glpIDC;
};
struct TDebuggingLog {
    int Timestamp;
    int DateTimestamp;
    int LogToFile;
    int LogToOutput;
    int Sequence;
    int Flush;
    int LogIsOpen;
    int LogError;
    ulong LogStartTickCount;
    ulong SeqNo;
    char[800] TBuff;
    char[1000] osbuf;
    char[128] Filename;
};
struct TDialogPanel {
    void * dlg_wnd;
    TPanel * save_parent_child;
    int text_font_id;
    int input_font_id;
    int button_font_id;
    int button_sound_id;
};
struct TDigital {
    TSound_Driver * sound_system;
    TDigital * owner;
    uchar loaded;
    uchar failed;
    char[13] sound_file;
    long resource_id;
    long volume;
    ulong pitch;
    long pan;
    int loop;
    uchar * wave_data;
    tWAVEFORMATEX * wave_info;
    IDirectSoundBuffer * sound_buffer;
    ulong data_size;
};
struct TDrawArea {
    TDrawSystem * DrawSystem;
    void * Wnd;
    uchar * Bits;
    BITMAPINFO256 * BitmapInfo;
    void * Bitmap;
    void * OldBitmap;
    int Width;
    int Height;
    int Pitch;
    int Orien;
    tagRECT ClipRect;
    void * DrawDc;
    IDirectDrawSurface * DrawSurface;
    _DDSURFACEDESC SurfaceDesc;
    DrawAreaNode * Node;
    char * Name;
    uchar * LastBits;
    int LastPitch;
    void * * DisplayOffsets;
    void * * CurDisplayOffsets;
    void * * FloatOffsets;
    RGE_Color_Table * shadow_color_table;
    TSpan_List_Manager * SpanList;
    TSpan_List_Manager * CurSpanList;
    int Float_X_Delta;
    int Float_Y_Delta;
    int DisplayOffsetsSz;
    int FloatOffsetsSz;
    int SystemMemOnly;
    int UsingVidMem;
    int UseTrans;
    int IsPrimarySurface;
    int Restored;
    int ExtendedLines;
    uchar TransColor;
};
struct TDrawSystem {
    void * Inst;
    void * Wnd;
    void * Pal;
    TDrawArea * DrawArea;
    TDrawArea * PrimaryArea;
    DrawAreaNode * DrawAreaList;
    IDirectDraw * DirDraw;
    IDirectDrawSurface * PrimarySurface;
    IDirectDrawClipper * Clipper;
    IDirectDrawPalette * DirDrawPal;
    ulong Flags;
    int ScreenWidth;
    int ScreenHeight;
    int ColorBits;
    int ErrorCode;
    int ChangedMode;
    int IsBanked;
    int CanSrcBlt;
    int Restored;
    int ModeAvail640;
    int ModeAvail800;
    int ModeAvail1024;
    int ModeAvail1280;
    int ModeAvail320_200;
    int ModeAvail320_240;
    int ModeAvail320_200_16;
    int ModeAvail320_240_16;
    int ModeAvail640_16;
    int ModeAvail800_16;
    int ModeAvail1024_16;
    tagPALETTEENTRY[256] palette;
    uchar DrawType;
    uchar ScreenMode;
};
struct TDropDownButtonPanel {
    TDropDownPanel * drop_down_panel;
};
struct TDropDownPanel {
    TTextPanel * val_panel;
    TButtonPanel * btn_panel;
    TListPanel * list_panel;
    TScrollBarPanel * scbar_panel;
    DropdownMode mode;
    short val_num;
    long val_wid;
    long val_hgt;
    long btn_wid;
    long btn_hgt;
    long list_wid;
    long list_hgt;
    long scbar_wid;
    long scbar_arrow_hgt;
    long scbar_tab_hgt;
    uchar list_is_above;
    long font_hgt;
    int outline_color;
    DrawStyle draw_style;
    int draw_val_rect;
};
struct TEasy_Panel {
    long ideal_width;
    long ideal_height;
    char[260] info_file_name;
    long info_id;
    TShape * background_pic;
    TShape * background_pic2;
    void * palette;
    char[260] cursor_file;
    long cursor_id;
    int background_pos;
    int use_bevels;
    uchar bevel_color1;
    uchar bevel_color2;
    uchar bevel_color3;
    uchar bevel_color4;
    uchar bevel_color5;
    uchar bevel_color6;
    ulong text_color1;
    ulong text_color2;
    ulong focus_color1;
    ulong focus_color2;
    ulong state_color1;
    ulong state_color2;
    char[260] popup_info_file_name;
    long popup_info_id;
    TShape * button_pics;
    RGE_Color_Table * shadow_color_table;
    long shadow_amount;
    uchar background_color1;
    uchar background_color2;
    int enable_ime;
    uchar help_mode;
    int stock_brush;
    void * brush;
    ulong brush_color;
    TDrawArea * shadow_area;
    int allow_shadow_area;
    int saved_mouse_mode;
};
struct Tech_Player_Tree {
    float research_done;
    short state;
};
struct Tech_Tree {
    char * name;
    short[4] pre_reqs;
    short pre_reqs_required;
    short[3] attribute;
    short[3] attribute_cost;
    uchar[3] attribute_used;
    short research;
    short effect;
    short track;
    short icon;
    uchar button_location;
    short build_obj_id;
    short string_id;
    short string_id2;
    long help_string_id;
    long help_page_id;
    long hotkey_id;
};
struct TechnologyItem {
    TechnologyItem * next;
    TechnologyItem * prev;
    int idValue;
    char[64] nameValue;
    ResourceItem * resourceCostValue;
};
struct TEditPanel {
    void * edit_wnd;
    short fixed_len;
    char * text;
    int text_len;
    int hidden;
    void * brush;
    int stock_brush;
    void * old_sub_wnd_proc;
    ulong text_color1;
    ulong text_color2;
    ulong highlight_text_color1;
    ulong highlight_text_color2;
    ulong back_color;
    FormatType format;
    void * font;
    int multi_line;
    tagRECT draw_rect;
    uint draw_format;
    int auto_sel;
    int sel_len;
    int bevel_type;
    uchar bevel_color1;
    uchar bevel_color2;
    uchar bevel_color3;
    uchar bevel_color4;
    uchar bevel_color5;
    uchar bevel_color6;
    int bevel_size;
    ulong imc;
    int enable_ime;
    int turn_ime_on;
};
struct TextNode {
    char * text;
    char * text2;
    long id;
    TextNode * next_node;
};
struct THelpDialog {
    long help_page_id;
    char[256] parent_panel;
    TTextPanel * title;
    TTextPanel * list;
    TButtonPanel * ok_button;
    TButtonPanel * encyclopedia_button;
};
struct THorizontalSliderPanel {
};
struct Tile_BlackEdge_Table {
    VSpanMiniList * black_UNdraw;
};
struct Tile_FogEdge_Table {
    VSpanMiniList * normal_draw;
    VSpanMiniList * fog_draw;
};
struct Time_Line_Panel {
    void * axis_font;
    long axis_font_wid;
    long axis_font_hgt;
    void * body_font;
    long body_font_wid;
    long body_font_hgt;
    Style text_style;
    ulong text_color1;
    ulong text_color2;
    ulong highlightTextColor1;
    ulong highlightTextColor2;
    long text_wid;
    long text_hgt;
    TShape * background_pic;
    short background_pic_wid;
    short background_pic_hgt;
    int fill_back;
    uchar back_color;
    int outline;
    uchar outline_color;
    int sorted;
    int bevel_type;
    uchar bevel_color1;
    uchar bevel_color2;
    uchar bevel_color3;
    uchar bevel_color4;
    uchar bevel_color5;
    uchar bevel_color6;
    TShape * special_events_pic;
    short special_events_pic_wid;
    short special_events_pic_hgt;
    long X_start_line_pos;
    long Y_start_line_pos;
    long X_line_pos;
    long Y_line_pos;
    long X_line_max_width;
    long Y_line_max_length;
    long X_axis_length;
    long Y_axis_length;
    float bar_thickness;
    long pop_reading_rate;
    float time_slice_drop_rate;
    long total_slices_to_drop;
    uchar drop_flag;
    long num_entries_page;
    long num_history_entries;
    Special_Events * time_slice_events;
    uchar timeline_flag;
    TTextPanel *[3] legend_entry_text;
};
struct TInputPanel {
    uchar caret_color;
    ulong caret_interval;
    ulong caret_last_time;
    int draw_caret;
    TDigital * overLengthSound;
    FormatType format_type;
    char * input_buffer;
    char * input_buffer1;
    char * input_buffer2;
    short input_len;
    short max_len;
    int insert_mode;
    short input_pos;
};
struct TListDialog {
    TTextPanel * title;
    TListPanel * list;
    TScrollBarPanel * scroll_bar;
    TButtonPanel * ok_btn;
    TButtonPanel * cancel_btn;
    short list_id;
    char * list_name;
};
struct TListPanel {
    int auto_track;
    ulong mouse_scroll_last_time;
    ulong mouse_scroll_interval;
    int mouse_scroll_up;
    int mouse_scroll_down;
    int drawHighlightBar;
};
struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};
struct TMessageDialog {
    uchar dlg_type;
    TTextPanel * text;
    TButtonPanel *[3] button;
};
struct TMessagePanel {
    MessageType message_type;
    char[512] text;
    int showing_message;
    ulong start_time;
    long show_message_interval;
    void * font;
    long font_wid;
    long font_hgt;
    uchar font_color;
    uchar back_color;
    int index_color;
    ulong font_color1;
    ulong font_color2;
    JustType horz_just;
    JustType vert_just;
    int word_wrap;
    void * image_clip_region;
    TDrawArea * ImageBuffer;
    tagRECT ImageRect;
    tagRECT UsedImageRect;
    tagRECT UsedScreenRect;
    int LastIBWidth;
    int LastIBHeight;
    int ImageTextActive;
    TShape * Icon1;
    TShape * Icon2;
    int IconFrame1;
    int IconFrame2;
};
struct tMIXERCONTROLDETAILS {
    ulong cbStruct;
    ulong dwControlID;
    ulong cChannels;
    ulong cbDetails;
    void * paDetails;
};
struct tMIXERCONTROLDETAILS_UNSIGNED {
    ulong dwValue;
};
struct TMousePointer {
    int custom_draw;
    TDrawArea * render_area;
    TDrawArea * save_area;
    TDrawArea * primary_area;
    int Num_Cursors;
    int Max_Cursors;
    TDrawArea *[16] cursors;
    TShape * Cursor_Shape;
    int Mouse_Mode;
    int Max_CX;
    int Max_CY;
    int cWidth;
    int cHeight;
    int gWidth;
    int gHeight;
    long mouse_x;
    long mouse_y;
    long save_x;
    long save_y;
    int facet;
    int game_facet;
    int next_facet;
    int last_facet;
    int d_top;
    int d_left;
    int d_bottom;
    int d_right;
    int g_top;
    int g_left;
    int g_bottom;
    int g_right;
    int save_area_valid;
    tagRECT save_rect;
    tagRECT mouse_rect;
    tagRECT cursor_rect;
    tagRECT new_save_rect;
    tagRECT restore_rect;
    tagRECT game_window;
    IDirectDrawSurface * restoreSurface;
    IDirectDrawSurface * renderSurface;
    IDirectDrawSurface * PrimarySurface;
    int active;
    int drawn;
    int Shutdown;
    int Setup;
    int GameMode;
    int GameEnabled;
    int MouseOnScreen;
    ulong LastDrawTime;
    long LastddError;
    char[260] cursor_file;
    int cursor_file_id;
};
struct TMusic_System {
    char[260] path;
    uchar music_type;
    TSound_Driver * sound_system;
    void * instance;
    void * window;
    int device_open;
    uint device_id;
    tagMCI_PLAY_PARMS play_info;
    uchar playing_track;
    char[261] file_name;
    int start_track;
    int end_track;
    int make_cur_track;
    ulong set_pos;
    int loop;
    int current_track;
    int track_count;
    int notify_waiting;
    long start_volume;
    long volume;
    int paused;
    int auto_paused;
    int inactivated;
    int fade_out;
    ulong fade_time;
    int fading_track;
    long fade_volume;
    ulong last_fade_time;
    int mixer_open;
    void * mixer_handle;
    tagMIXERLINEA mixer_line_info;
    tagMIXERLINECONTROLSA mixer_line_controls;
    tagMIXERCONTROLA mixer_volume_control;
    tMIXERCONTROLDETAILS mixer_volume_details;
    tMIXERCONTROLDETAILS_UNSIGNED mixer_volume_value;
    void * midi_window;
    ulong last_check_time;
};
struct TPanel {
    TPanel * previousPanelValue;
    TPanel * previousModalPanelValue;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char * panelNameValue;
    TDrawArea * render_area;
    tagRECT clip_rect;
    PositionMode position_mode;
    RedrawMode need_redraw;
    TPanel * curr_child;
    TPanel * parent_panel;
    TPanel * left_panel;
    TPanel * top_panel;
    TPanel * right_panel;
    TPanel * bottom_panel;
    PanelNode * node;
    PanelNode * first_child_node;
    PanelNode * last_child_node;
    TPanel * tab_prev_panel;
    TPanel * tab_next_panel;
    int mouse_captured;
    int active;
    int visible;
    int tab_stop;
    int have_focus;
    int overlapping_children;
    int handle_mouse_input;
    int just_drawn;
    void * clip_rgn;
    tagRECT render_rect;
    long left_border;
    long top_border;
    long right_border;
    long bottom_border;
    long min_wid;
    long max_wid;
    long min_hgt;
    long max_hgt;
    long mouse_hold_interval;
    long mouse_move_tolerance;
    long mouse_down_x;
    long mouse_down_y;
    int mouse_down_ctrl;
    int mouse_down_shift;
    ulong mouse_down_time;
    int error_code;
    int z_order;
    int display_changed_count;
    long help_string_id;
    long help_page_id;
    uchar mouse_action;
    uchar mouse_down_button;
    uchar panel_type;
    uchar color;
    uchar fill_in_background;
    uchar clip_to_parent;
    uchar draw_rect2_flag;
    uchar need_restore;
};
struct TPanelSystem {
    TPanel * mouseOwnerValue;
    TPanel * keyboardOwnerValue;
    TPanel * modalPanelValue;
    TPanel * currentPanelValue;
    PanelNode * panelListValue;
    int numberActivePanelsValue;
    TPanel * prevCurrentChildValue;
    void *[10] palette;
    char[10][260] palette_file;
    int[10] palette_use_count;
    long[10] palette_id;
    ulong Imc;
    int ImeEnabled;
    int ImeOn;
    int InputEnabled;
    int saved_colors;
    ulong save_back_color;
    ulong save_text_color;
};
struct TPicture {
    tagBITMAPINFOHEADER * Dib;
    BITMAPINFO256 * BitmapInfo;
    uchar * Bits;
    TRANSINFO * TransInfo;
    int OwnMemory;
    long Width;
    long Height;
    short Orien;
};
struct TPicturePanel {
    char[12] pic_name;
    long res_id;
    int size_from_pic;
    int keep_loaded;
    int own_pic;
    PictureType pic_type;
    TPicture * pic;
    TShape * shape;
};
struct Trade_Avail {
    RGE_Player * player;
    RGE_Static_Object * dock;
    float inventory;
};
struct TradeAIModule {
    MainDecisionAIModule * md;
};
struct TRANSINFO {
    int AnyTrans;
    long x;
    long y;
    long w;
    long h;
    LINEINFO * LineInfo;
};
struct TRegistry {
    void * ghMachineKey;
    void * ghUserKey;
    void * ghMachineKeyRead;
    ulong gdwDisp;
    char[255] Data;
};
struct TRIBE_Action {
};
struct TRIBE_Action_Artifact {
};
struct TRIBE_Action_Build {
};
struct TRIBE_Action_Convert {
    uchar was_same_owner;
    float requiredRange;
};
struct TRIBE_Action_Discovery_Artifact {
    uchar * flags;
};
struct TRIBE_Action_Heal {
};
struct TRIBE_Action_Hunt {
    int targetType;
};
struct TRIBE_Action_List {
};
struct TRIBE_Action_Make_Obj {
    short obj_id;
    float work_done;
    int unique_id;
    uchar pre_paid;
};
struct TRIBE_Action_Make_Tech {
    short tech_id;
    int unique_id;
};
struct TRIBE_Action_Repair {
    uchar save_target_command_flag;
};
struct TRIBE_Action_Trade {
    float pick_up_x;
    float pick_up_y;
};
struct TRIBE_Action_Wonder {
};
struct TRIBE_Building_Object {
    Production_Queue_Record * production_queue;
    short production_queue_size;
    short production_queue_count;
    uchar production_queue_enabled;
    RGE_Action_List * production_queue_actions;
    uchar production_queue_change_flag;
    uchar production_queue_auto_paused;
    short production_queue_need_attr;
    float build_pts;
    int unique_build_id;
    uchar culture;
    uchar built;
    int DoppleInstalled;
    ulong PriorMap1;
    ulong PriorMap2;
    ulong PriorMap3;
    long PriorTurn1;
    long PriorTurn2;
    long PriorTurn3;
};
struct TRIBE_Campaign_Editor_Screen {
    uchar need_to_save;
    TTextPanel * title;
    TTextPanel * filename_title;
    TTextPanel * scenarios_title;
    TTextPanel * campaign_scenarios_title;
    TListPanel * scenarios;
    TListPanel * campaign_scenarios;
    TScrollBarPanel * scenarios_bar;
    TScrollBarPanel * campaign_scenarios_bar;
    TEditPanel * filename;
    TButtonPanel * ok_button;
    TButtonPanel * cancel_button;
    TButtonPanel * save_button;
    TButtonPanel * add_button;
    TButtonPanel * remove_button;
    TButtonPanel * move_scenario_up_button;
    TButtonPanel * move_scenario_down_button;
    TDropDownPanel * filename_drop;
    RGE_Campaign * campaign;
};
struct TRIBE_Cliff_Info {
    long[4] info;
};
struct TRIBE_Combat_Object {
    uchar own_master;
};
struct TRIBE_Command {
};
struct TRIBE_Command_Attack_Ground {
    uchar command;
    uchar unit_num;
    float location_x;
    float location_y;
};
struct TRIBE_Command_Build {
    uchar command;
    uchar unit_num;
    uchar unit_player_id;
    float location_x;
    float location_y;
    short obj_id;
    int unique_id;
};
struct TRIBE_Command_Build_Wall {
    uchar command;
    uchar unit_num;
    uchar unit_player_id;
    uchar x1;
    uchar y1;
    uchar x2;
    uchar y2;
    short obj_id;
    int unique_id;
};
struct TRIBE_Command_Cancel_Build {
    uchar command;
    int unit_id;
};
struct TRIBE_Command_Explore {
    uchar command;
    uchar numUnits;
    uchar unit_player_id;
    float targetXPosition;
    float targetYPosition;
};
struct TRIBE_Command_Game {
    uchar command;
    uchar game_command;
    short var1;
    short var2;
    float var3;
    short var4;
};
struct TRIBE_Command_Give_Attribute {
    uchar command;
    uchar player_id;
    uchar to_player_id;
    uchar attr_id;
    float attr_amount;
    float attr_cost;
};
struct TRIBE_Command_Make {
    uchar command;
    int unit_id;
    uchar unit_player_id;
    short obj_id;
    int unique_id;
};
struct TRIBE_Command_Queue {
    uchar command;
    long bldg_id;
    short train_id;
    short train_count;
};
struct TRIBE_Command_Repair {
    uchar command;
    uchar unit_num;
    RGE_Obj_Info target;
};
struct TRIBE_Command_Research {
    uchar command;
    int unit_id;
    uchar unit_player_id;
    short tech_id;
    int unique_id;
};
struct TRIBE_Command_Trade_Attribute {
    uchar command;
    uchar unit_num;
    long attribute;
};
struct TRIBE_Command_Unload {
    uchar command;
    uchar unit_num;
    float location_x;
    float location_y;
};
struct TRIBE_Credits_Screen {
    TScrollTextPanel * text_panel;
    int text_set;
    int picture_set;
    ulong last_picture_time;
    ulong last_pause_time;
    ScreenMode mode;
    tagPALETTEENTRY[256] color_table;
    tagPALETTEENTRY color;
    TShape *[7] back_pics;
    int first_draw;
    int text_done;
};
struct TRIBE_Dialog_List {
};
struct TRIBE_Dialog_Name {
    TTextPanel * title;
    TTextPanel * name_text;
    TEditPanel * name_input;
    TButtonPanel * ok_button;
    TButtonPanel * cancel_button;
};
struct TRIBE_Dialog_Sed_Menu {
    TRIBE_Screen_Sed * scenario_editor;
    TTextPanel * title;
    TButtonPanel *[7] buttons;
};
struct TRIBE_Diamond_Map_View {
    ulong last_attack_time;
    int flash_on;
};
struct TRIBE_Effects {
};
struct TRIBE_Gaia {
    float update_time;
    long update_nature;
    long last_count;
    long animal_max;
};
struct TRIBE_Game {
    MouseClickInfo * MouseRightClickTable;
    int MouseRightClickTableSize;
    MouseClickInfo * MouseLeftClickTable;
    int MouseLeftClickTableSize;
    long[9] queue_is_waiting_on_pop_counter;
    int[9] random_civ;
    TRIBE_Game_Options tribe_game_options;
    char[260] testing_scenario;
    void * video_window;
    int cur_video;
    void * old_video_wnd_proc;
    int video_paused;
    ulong last_video_time;
    int video_setup;
    int video_double_size;
    int video_changed_res;
    int video_hi_color;
    long video_save_res_wid;
    long video_save_res_hgt;
    void * video_save_palette;
    int started_menu_music;
    int show_object_id;
    TRIBE_Screen_Game * game_screen;
    long[5] notification_loc_x;
    long[5] notification_loc_y;
    long current_notification_loc;
    long current_notification_recalled;
    char[260] startup_scenario;
    char[260] startup_game;
    ulong auto_exit_time;
    char[260] save_game_name;
    char[260] load_game_name;
    char[256] timing_text2;
    int[9] save_humanity;
    uchar quick_start_game;
    int random_start_value;
    uchar[18][10] computerNameUsed;
    void * handleIdleLock;
    int inHandleIdle;
};
struct TRIBE_Game_Options {
    MapSize mapSizeValue;
    MapType mapTypeValue;
    int animalsValue;
    int predatorsValue;
    VictoryType victoryTypeValue;
    int victoryAmountValue;
    uchar[9] civilizationValue;
    int[9] scenarioPlayerValue;
    uchar[9] playerColorValue;
    uchar[9] computerNameValue;
    uchar allowTradingValue;
    uchar longCombatValue;
    uchar randomizePositionsValue;
    uchar fullTechTreeValue;
    ResourceLevel resourceLevelValue;
    Age startingAgeValue;
    uchar startingUnitsValue;
    uchar deathMatchValue;
    uchar popLimitValue;
};
struct TRIBE_History_Entry {
    uchar population;
};
struct TRIBE_History_Events {
    uchar event;
    long time;
    long world_time;
    TRIBE_History_Events * next;
};
struct TRIBE_History_Info {
    TRIBE_History_Entry * history;
    TRIBE_History_Events * events;
    long number_of_events;
    long number_of_entries;
    long max_number_of_entries;
};
struct TRIBE_Main_View {
};
struct TRIBE_Map {
    TRIBE_Game * Game;
    RGE_Player * rge_player;
    RGE_Game_World * rge_game_world;
    RGE_Map_Gen_Info * rge_map_gen_information;
    uchar * zones;
    long old_cliff_x;
    long old_cliff_y;
    long safe_cliff_x;
    long safe_cliff_y;
    long old_cliff_direction;
    TRIBE_Master_Cliff_Info[256] cliff_master_table;
};
struct TRIBE_Master_Building_Object {
    RGE_Sound * construction_sound;
    RGE_Sprite * construction_sprite;
    uchar building_connect_flag;
    short building_facet;
    uchar build_and_go_away;
    short on_build_make_obj;
    short on_build_make_tile;
    short on_build_make_overlay;
    short on_build_make_tech;
};
struct TRIBE_Master_Cliff_Info {
    long id;
    long facet;
    long id2;
    long facet2;
    TRIBE_Cliff_Info info;
    float offset_x;
    float offset_y;
};
struct TRIBE_Master_Combat_Object {
    Attribute_Cost[3] build_inventory;
    short build_pts_required;
    short id_of_building_obj;
    uchar button_location;
    short orig_pierce_armor;
};
struct TRIBE_Master_Player {
};
struct TRIBE_Master_Tree_Object {
};
struct TRIBE_Mission_Screen {
    TTextPanel * title;
    TTextPanel * list;
    TScrollBarPanel * scroll_bar;
    TButtonPanel * ok_button;
    TButtonPanel *[3] text_buttons;
    uchar game_flag;
    TPicture * vc_back_bmp;
};
struct TRIBE_Object_List {
};
struct TRIBE_Panel_Button {
    int display_garrison;
    int garrsion_number;
    uchar tribe_button_type;
    TShape * border_pic;
    uchar * color_table;
    int border_frame;
    char[256] text_msg;
    int in_use;
};
struct TRIBE_Panel_Inven {
    TShape * pics;
    TRIBE_Player * player;
    short save_attr_num;
    short * save_attr;
    ulong idle_time;
    ulong idle_interval;
    void * font;
    ulong font_color;
    ulong back_color;
};
struct TRIBE_Panel_Object {
    void * font;
    long font_wid;
    long font_hgt;
    TShape * health_pic;
    TShape * item_pic;
    TShape * unit_pics;
    TShape * * bldg_pics;
    TRIBE_Player * player;
    RGE_Static_Object * game_obj;
    ulong idle_time;
    ulong idle_interval;
    uchar mode;
    RGE_Master_Static_Object * save_obj_type;
    RGE_Sprite * save_sprite;
    short save_attr_type;
    float save_attr_amount;
    uchar save_object_state;
    float save_build_pts;
    RGE_Object_Node * save_list;
    short save_number_of_objects;
    uchar save_can_debark;
    float save_world_x;
    float save_world_y;
    float save_hp;
    short save_armor;
    short save_pierce_armor;
    short save_weapon;
    float save_weapon_range;
    float save_speed_of_attack;
    short save_work_type;
    short save_work_target;
    short save_progress;
    char[100] save_name;
    uchar save_facet;
    float save_angle;
    float save_los;
    int save_pop;
    int save_max_pop;
    uchar save_selected_group;
    RGE_Player * save_owner;
    int save_age;
    uchar save_have_action;
    int[9] save_score;
    int save_farm_amt;
};
struct TRIBE_Panel_Pop {
    void * font;
    ulong color1;
    ulong color2;
    ulong color3;
    int player_id;
    TRIBE_World * world;
    TRIBE_Player * player;
    int pop;
    int max_pop;
    uchar mode;
    float timer;
    void * image_clip_region;
    TDrawArea * ImageBuffer;
    tagRECT ImageRect;
    tagRECT UsedImageRect;
    tagRECT UsedScreenRect;
    int ImageTextActive;
    int LastIBWidth;
    int LastIBHeight;
};
struct TRIBE_Panel_Text_Line {
    void * font;
    uchar text_type;
    char[200] text;
    long id;
};
struct TRIBE_Panel_Time {
    void * font;
    ulong color1;
    ulong color2;
    int clock_type;
    int old_clock_type;
    int clock_format;
    int old_clock_format;
    int player_id;
    TRIBE_World * world;
    TRIBE_Player * player;
    ulong start_real_time;
    ulong game_time;
    ulong last_game_time;
    ulong display_time;
    ulong last_display_time;
    void * image_clip_region;
    TDrawArea * ImageBuffer;
    tagRECT ImageRect;
    tagRECT UsedImageRect;
    tagRECT UsedScreenRect;
    int ImageTextActive;
    int LastIBWidth;
    int LastIBHeight;
};
struct TRIBE_Player {
    TRIBE_Player_Tech * tech_tree;
    long fog_update;
    long update_count;
    long update_history_count;
    long updateCountNeedHelp;
    float update_time;
    TribeMainDecisionAIModule * playerAI;
    char[256] aiStatusInformationValue;
    char[256] aiStatusInformationValue2;
    char[256] aiStatusInformationValue3;
    char[256] aiStatusInformationValue4;
    char[256] aiStatusInformationValue5;
    char[256] aiStatusInformationValue6;
    TRIBE_History_Info * history;
    float ruin_held_time;
    float artifact_held_time;
};
struct TRIBE_Player_Tech {
    Tech_Player_Tree * tech_player_tree;
    short tech_player_tree_num;
    TRIBE_Tech * base_tech;
    RGE_Player * owner;
};
struct TRIBE_RMM_Database_Controller {
};
struct TRIBE_Scenario_Editor_Panel_Object {
    RGE_Master_Static_Object * master_game_obj;
    int master_culture_id;
};
struct TRIBE_Scenario_Header {
    int any_sp_victory;
    int active_player_count;
};
struct TRIBE_Screen_Campaign_Selection {
    TTextPanel * title;
    long campaignListX;
    long campaignListY;
    long campaignListWidth;
    long campaignListHeight;
    TTextPanel * campaignTitle;
    TListPanel * campaignList;
    TScrollBarPanel * campaignScrollbar;
    long scenarioListX;
    long scenarioListY;
    long scenarioListWidth;
    long scenarioListHeight;
    TTextPanel * scenarioTitle;
    TListPanel * scenarioList;
    TScrollBarPanel * scenarioScrollbar;
    TTextPanel * difficultyTitle;
    TDropDownPanel * difficultyDrop;
    TButtonPanel * okButton;
    TButtonPanel * cancelButton;
    TButtonPanel * close_button;
    int campaignsLoaded;
};
struct TRIBE_Screen_Disconnect {
    int mode;
    TTextPanel * message;
    TButtonPanel * cancel_button;
    TButtonPanel * close_button;
};
struct TRIBE_Screen_Game {
    TShape * game_screen_pic;
    TShape * button_border1_pic;
    TShape * button_other_pic;
    TShape * button_border2_pic;
    TShape * button_border3_pic;
    TShape * button_cmd_pic;
    TShape * button_tech_pic;
    TShape * button_unit_pic;
    TShape *[5] button_bldg_pics;
    TShape * more_cancel_pic;
    short more_frame;
    short cancel_frame;
    short unselect_frame;
    TRIBE_Main_View * main_view;
    TRIBE_Diamond_Map_View * map_view;
    TRIBE_Panel_Inven * inven_panel;
    TRIBE_Panel_Object * object_panel;
    TRIBE_Panel_Button *[17] button_panel;
    TMessagePanel * text_line_panel;
    TTextPanel * quit_message_panel;
    TRIBE_Panel_Time * time_panel;
    TRIBE_Panel_Time *[10] countdown_clock;
    TRIBE_Panel_Pop * pop_panel;
    TMessagePanel * message_panel;
    TMessagePanel * message_panel2;
    TMessagePanel * message_panel3;
    TMessagePanel * message_panel4;
    TMessagePanel * message_panel5;
    TMessagePanel * message_panel6;
    TMessagePanel *[8] chat_panel;
    RGE_Panel_Tool_Box * tool_box;
    TTextPanel * age_panel;
    TTextPanel * pause_text;
    TTextPanel * fps_panel;
    TMessagePanel *[8] score_panel;
    TTextPanel * log_text;
    TScrollBarPanel * log_scrollbar;
    TRIBE_World * world;
    ulong update_interval;
    ulong last_update_time;
    ulong map_redraw_interval;
    ulong last_map_redraw_time;
    RGE_Static_Object * game_obj;
    short sel_count;
    Item_Avail * tech_list;
    Item_Avail * make_list;
    Item_Avail * bldg_list;
    Trade_Avail * trade_list;
    short item_cnt;
    short start_item;
    short last_item;
    __unnamed[9] port_info;
    ulong terrain_sound_interval;
    ulong last_terrain_sound_time;
    RGE_Sound * terrain_sound;
    int terrain_playing;
    ulong terrain_sound_start_time;
    int anim_pal;
    ulong anim_pal_interval;
    ulong last_anim_pal_time;
    short last_anim_pal_index;
    short last_anim_pal_index2;
    short last_anim_pal_index3;
    __unnamed[7] anim_pal_table;
};
struct TRIBE_Screen_Info {
    int auto_close;
    ulong timer;
    ulong last_time;
};
struct TRIBE_Screen_Main_Error {
    TTextPanel * message;
    TButtonPanel * cancel_button;
    TButtonPanel * close_button;
};
struct TRIBE_Screen_Main_Menu {
    TTextPanel * title1;
    TTextPanel * title2;
    TButtonPanel *[7] button;
    TTextPanel * ms_title_text;
    TTextPanel * ms_copy_text1;
    TTextPanel * ms_copy_text2;
    TTextPanel * warning_text;
    TPicturePanel * circle_p_pic;
};
struct TRIBE_Screen_Name {
    TTextPanel * title;
    TTextPanel * name_text;
    TListPanel * name_list;
    TScrollBarPanel * name_scrollbar;
    TButtonPanel * new_button;
    TButtonPanel * remove_button;
    TButtonPanel * ok_button;
    TButtonPanel * cancel_button;
    TButtonPanel * close_button;
    int started_input;
};
struct TRIBE_Screen_Sed {
    int is_multi_player;
    int set_player_first_flag;
    RGE_Static_Object * SelectedObject;
    RGE_Static_Object * DestinationObject;
    float px1;
    float py1;
    float px2;
    float py2;
    int CurrentVictory;
    int CurrentPlayer;
    SELECT_REGION_e SelectRegionFlag;
    ScenarioMode scenario_mode;
    MapType map_type;
    VictoryType mp_victory_type;
    BrushSize brush_size;
    PaintType paint_type;
    short player_num;
    MessageType message_type;
    uchar need_to_save_flag;
    uchar valid_save_spot_flag;
    TShape * background_pic;
    TRIBE_Main_View * main_view;
    RGE_Diamond_Map_View * map_view;
    TMessagePanel * message_panel;
    TPanel * bottom_panel;
    TButtonPanel *[10] scenario_mode_button;
    TButtonPanel * menu_button;
    TButtonPanel * help_button;
    TButtonPanel *[3] map_type_button;
    TTextPanel *[3] map_type_text;
    TTextPanel * map_type_label;
    TTextPanel * default_terrain_label;
    TDropDownPanel * default_terrain_drop;
    TTextPanel * map_size_label;
    TDropDownPanel * map_size_drop;
    TTextPanel * map_style_label;
    TDropDownPanel * map_style_drop;
    TTextPanel * random_seed_label;
    TEditPanel * random_seed_input;
    TTextPanel * random_seed_used_label;
    TTextPanel * random_seed_used_text;
    TButtonPanel * generate_map_button;
    TTextPanel * map_generating_text;
    TTextPanel * brush_size_label;
    TButtonPanel *[5] brush_size_button;
    TTextPanel *[5] brush_size_button_label;
    TTextPanel * paint_type_label;
    TButtonPanel *[3] paint_type_button;
    TTextPanel *[3] paint_type_button_label;
    TTextPanel * paint_terrain_label;
    TListPanel * paint_terrain_list;
    TScrollBarPanel * paint_terrain_scrollbar;
    TListPanel * paint_elevation_list;
    TScrollBarPanel * paint_elevation_scrollbar;
    TTextPanel * player_label;
    TDropDownPanel * player_list;
    TDropDownPanel * player_number_list;
    TDropDownPanel * player_advance_civilization_drop;
    TButtonPanel * player_advance_civilization_button;
    TTextPanel *[5] player_inven_label;
    TEditPanel *[5] player_inven_input;
    TTextPanel *[2] player_setting_label;
    TTextPanel * player_starting_age_label;
    TDropDownPanel *[2] player_setting_drop;
    TDropDownPanel * BuildList;
    TDropDownPanel * CityLayout;
    TDropDownPanel * AiRules;
    TTextPanel * player_build_text;
    TTextPanel * player_city_text;
    TTextPanel * AiRules_text;
    TDropDownPanel * unit_player_list;
    TButtonPanel *[4] unit_mode_select;
    TTextPanel *[4] unit_mode_select_label;
    TListPanel * unit_list;
    TScrollBarPanel * unit_scrollbar;
    List_Info * unit_list_info;
    TShape * button_unit_pics;
    TShape *[5] button_bldg_pics;
    TRIBE_Scenario_Editor_Panel_Object * object_panel;
    short unit_list_size;
    TButtonPanel *[6] victory_cond_on;
    TButtonPanel *[2] victory_and_or;
    TTextPanel * victory_condition_label;
    TTextPanel * victory_amount_label;
    TTextPanel * victory_long_label;
    TTextPanel *[2] victory_text_and_or;
    TTextPanel * victory_label_conquest;
    TTextPanel * victory_label_explore;
    TTextPanel * victory_label_explore_percent;
    TTextPanel * victory_label_ruins;
    TTextPanel * victory_label_artifacts;
    TTextPanel * victory_label_discoveries;
    TTextPanel * victory_label_gold;
    TEditPanel * victory_condition_explore;
    TEditPanel * victory_condition_ruins;
    TEditPanel * victory_condition_artifacts;
    TEditPanel * victory_condition_discoveries;
    TEditPanel * victory_condition_gold;
    TTextPanel *[5] victory_cond_type_label;
    TButtonPanel *[5] victory_cond_type;
    TTextPanel * victory_score_label;
    TDropDownPanel * victory_score;
    TTextPanel * victory_time_label;
    TDropDownPanel * victory_time;
    TButtonPanel *[12] victory_button;
    TDropDownPanel * victory_drop_down;
    TDropDownPanel * victory_object_list;
    TDropDownPanel * victory_player_list;
    TDropDownPanel * victory_enemy_player_list;
    TDropDownPanel * victory_attribute_list;
    TDropDownPanel * victory_ages_list;
    TDropDownPanel * victory_tech_list;
    TButtonPanel * victory_button_set_object;
    TButtonPanel * victory_button_set_destination;
    TButtonPanel * victory_button_go_to_dest;
    TTextPanel * victory_condition_text;
    TTextPanel * victory_condition_type;
    TTextPanel * victory_amount_text;
    TTextPanel * victory_which_enemy_text;
    TEditPanel * victory_amount_input;
    TScrollBarPanel * victory_object_scrollbar;
    TEditPanel * message_input;
    TButtonPanel *[5] message_button;
    TTextPanel *[5] message_button_label;
    long current_message;
    TTextPanel *[4] cinematic_label;
    TDropDownPanel *[4] cinematic_input;
    TTextPanel *[1] options_label;
    TButtonPanel *[1] options_button;
    TDropDownPanel * options_player_list;
    TTextPanel * options_disable_tech_text;
    TButtonPanel *[16] options_disable_button;
    TTextPanel *[16] options_disable_text;
    TTextPanel *[8] Diplomacy_opponent_label;
    TTextPanel *[8] Diplomacy_player_text;
    TDropDownPanel * Diplomacy_player_list;
    TTextPanel *[4] Diplomacy_status_label;
    TButtonPanel *[8][3] Diplomacy_friend_box;
    TButtonPanel *[8] Diplomacy_AlliedVictory;
    TRIBE_World * world;
    ulong update_interval;
    ulong last_update_time;
    ulong map_redraw_interval;
    ulong last_map_redraw_time;
    int changed_system_colors;
    ulong save_text_color;
    ulong save_window_color;
};
struct TRIBE_Screen_Sed_Menu {
    TTextPanel * title;
    TButtonPanel *[4] button;
    TButtonPanel * close_button;
};
struct TRIBE_Screen_Sed_Open {
    TTextPanel * title;
    TListPanel * list;
    TScrollBarPanel * scrollbar;
    TButtonPanel * okButton;
    TButtonPanel * cancelButton;
    TButtonPanel * deleteButton;
};
struct TRIBE_Screen_Status_Message {
    TTextPanel * message;
};
struct TRIBE_Screen_Wait {
    TTextPanel * message;
    TButtonPanel * cancel_button;
    TButtonPanel * close_button;
    TTextPanel * scenarioName;
    TTextPanel *[20] settingText;
};
struct TRIBE_Task_List {
};
struct TRIBE_Tech {
    Tech_Tree * tech_tree;
    short tech_tree_num;
    TRIBE_World * world;
};
struct TRIBE_Tree_Object {
};
struct TRIBE_Victory_Conditions {
};
struct TRIBE_World {
    TRIBE_Tech * tech;
    int victory_type;
    int artifact_count;
    int ruin_count;
    uchar countdown_victory;
    float countdown_clock;
    uchar score_displayed;
    uchar controllingComputerPlayer;
    int sent_zone_score;
};
struct TRIBE_Zone_High_Score_Info {
    long score;
    uchar civ;
    char[16] player_name;
    uchar num_allies;
};
struct TRIBE_Zone_Info {
    uchar number_of_players;
    uchar number_of_computer_players;
    char[32] scenario_name;
    ulong game_time;
    TRIBE_Zone_High_Score_Info total_score;
    TRIBE_Zone_High_Score_Info religion_score;
    TRIBE_Zone_High_Score_Info economy_score;
    TRIBE_Zone_High_Score_Info combat_score;
    TRIBE_Zone_High_Score_Info research_score;
    TRIBE_Zone_Player_Info[8] player_info;
    TRIBE_Zone_Map_Info map_info;
    uchar cheats_enabled;
    uchar game_end_condition_code;
    ulong database_checksum;
    ulong code_checksum;
    ulong program_version;
};
struct TRIBE_Zone_Map_Info {
    uchar Map_Size;
    uchar Map_Type;
    short Pop_Limit;
    uchar Victory_Condition;
    uchar Start_Age;
    uchar Resources;
    uchar Full_Tech;
    uchar Fixed_Pos;
    uchar Reveal_Map;
    uchar Death_Match;
};
struct TRIBE_Zone_Player_Info {
    char[16] name;
    long score;
    uchar winner;
    uchar civ_played;
    uchar civ_random;
    uchar player_no;
    uchar team_no;
    uchar game_outcome;
    long tool_time;
    long bronze_time;
    long iron_time;
};
struct TribeAboutDialog {
    TTextPanel * title_text;
    TTextPanel * version_text;
    TTextPanel * ms_copy_text1;
    TTextPanel * ms_copy_text2;
    TTextPanel * ens_copy_text;
    TTextPanel * genie_copy_text;
    TTextPanel * pid_label_text;
    TTextPanel * pid_text;
    TTextPanel * warning_text;
    TTextPanel * background;
    TButtonPanel * credits_button;
    TButtonPanel * close_button;
    TPicturePanel * circle_p_pic;
};
struct TribeAchievementsScreen {
    int end_game_flag;
    int current_mode;
    int size;
    TTextPanel * title;
    TTextPanel * summary_text;
    TTextPanel * instruction;
    TTextPanel * win_loss_text;
    TTextPanel * time;
    TTextPanel *[7] title_bar;
    TTextPanel *[5] achievement_choice;
    TTextPanel *[8][7] statistics;
    TTextPanel *[8] player_names;
    TScrollBarPanel * summary_text_bar;
    TScrollBarPanel * instruction_bar;
    TScrollBarPanel * win_loss_text_bar;
    TButtonPanel * okButton;
    TButtonPanel * backButton;
    TButtonPanel * backButton2;
    TButtonPanel * timelineButton;
    TButtonPanel * aftermathButton;
    TButtonPanel * restartButton;
    TButtonPanel * close_button;
    TShape * win_decal;
    Time_Line_Panel * time_line;
};
struct TribeAIPlayBook {
};
struct TribeArtifactUnitAIModule {
};
struct TribeBuildAIModule {
    TribeMainDecisionAIModule * md;
};
struct TribeBuildingUnitAIModule {
};
struct TribeCivilianUnitAIModule {
};
struct TribeConfigDialog {
    Mode modeValue;
    TTextPanel * title;
    TTextPanel *[4] speedTitle;
    TButtonPanel *[3] speedButton;
    TTextPanel *[3] musicTitle;
    TVerticalSliderPanel * musicSlider;
    TTextPanel *[3] soundTitle;
    TVerticalSliderPanel * soundSlider;
    TTextPanel *[3] scrollSpeedTitle;
    TVerticalSliderPanel * scrollSpeedSlider;
    TTextPanel *[4] sizeTitle;
    TButtonPanel *[3] sizeButton;
    TTextPanel *[3] mouseTitle;
    TButtonPanel *[2] mouseButton;
    TTextPanel *[3] rolloverTitle;
    TButtonPanel *[2] rolloverButton;
    TTextPanel *[4] pathFindingTitle;
    TButtonPanel *[3] pathFindingButton;
    TButtonPanel * okButton;
    TButtonPanel * cancelButton;
    long musicVolume;
    long soundVolume;
    float gameSpeed;
    long scrollSpeed;
    long newMusicVolume;
    long newSoundVolume;
};
struct TribeConstructionAIModule {
    TribeMainDecisionAIModule * md;
};
struct TribeDiplomacyDialog {
    TTextPanel *[8] title;
    TTextPanel *[8] playerName;
    TTextPanel *[8] playerVictoryScores;
    TTextPanel *[8] playerCivilization;
    TTextPanel * needMarket;
    TButtonPanel *[8] goldTributeButton;
    TButtonPanel *[8] woodTributeButton;
    TButtonPanel *[8] foodTributeButton;
    TButtonPanel *[8] stoneTributeButton;
    TButtonPanel *[24] allyButton;
    TButtonPanel * allianceButton;
    TButtonPanel * okButton;
    TButtonPanel * clearButton;
    TButtonPanel * cancelButton;
    TButtonPanel * help_button;
    TShape * buttonPics;
    TShape * backgroundPics;
    float foodTotal;
    float woodTotal;
    float goldTotal;
    float stoneTotal;
    TTextPanel * playerFood;
    TTextPanel * playerGold;
    TTextPanel * playerWood;
    TTextPanel * playerStone;
    float[8] goldTributeAmount;
    float[8] foodTributeAmount;
    float[8] stoneTributeAmount;
    float[8] woodTributeAmount;
    int cur_player_row;
    int tribute_flag;
};
struct TribeElephantUnitAIModule {
};
struct TribeEndScreen {
    TPicturePanel * background;
    TTextPanel * title;
    TTextPanel * text;
    TButtonPanel * okButton;
};
struct TribeFishingShipUnitAIModule {
};
struct TribeGameSettingsScreen {
    TTextPanel * title;
    State state;
    TTextPanel * mapSizeLabel;
    TDropDownPanel * mapSizeDrop;
    TTextPanel * mapTypeLabel;
    TDropDownPanel * mapTypeDrop;
    TTextPanel * victoryTypeLabel;
    TDropDownPanel * victoryTypeDrop;
    TTextPanel * victoryFixedText;
    TTextPanel * percentLabel;
    TTextPanel * scoreLabel;
    TDropDownPanel * scoreDrop;
    TTextPanel * timeLabel;
    TDropDownPanel * timeDrop;
    TTextPanel * difficultyLabel;
    TDropDownPanel * difficultyDrop;
    TTextPanel * ageLabel;
    TDropDownPanel * ageDrop;
    TTextPanel * resourcesLabel;
    TDropDownPanel * resourcesDrop;
    TTextPanel * pathingLabel;
    TDropDownPanel * pathingDrop;
    TTextPanel * limitLabel;
    TDropDownPanel * limitDrop;
    TTextPanel * scenarioTitle;
    TTextPanel * scenarioPlayersTitle;
    long scenarioListX;
    long scenarioListY;
    long scenarioListWidth;
    long scenarioListHeight;
    TListPanel * scenarioList;
    TScrollBarPanel * scenarioScrollbar;
    int scenarioCount;
    char * * scenarioMission;
    int * scenarioFixed;
    int scenariosLoaded;
    TTextPanel * missionTitle;
    long missionTextX;
    long missionTextY;
    long missionTextWidth;
    long missionTextHeight;
    TTextPanel * missionText;
    TScrollBarPanel * missionScrollbar;
    TButtonPanel *[4] optionButton;
    TTextPanel *[4] optionText;
    TButtonPanel * okButton;
    TButtonPanel * cancelButton;
    TButtonPanel * help_button;
    TribeMPSetupScreen * chat_scr;
    int last_scenario_line;
    int scenario_line_offset;
    ulong last_send_shared;
};
struct TribeHuntedAnimalUnitAIModule {
};
struct TribeInformationAIModule {
    ManagedArray<int> farmsTaskedThisUpdate;
    TribeMainDecisionAIModule * md;
    int mapXSizeValue;
    int mapYSizeValue;
    int lastUpdateRowValue;
    int maxImportantObjectMemory;
    ObjectMemory * importantObjectMemory;
    ManagedArray<int> importantObjects;
    ManagedArray<int> importantUnits;
    ManagedArray<int> importantMiscs;
    ManagedArray<int> itemsToDefend;
    InfluenceMap pathMap;
    ManagedArray<int> playerObjects;
    ManagedArray<int> playerBuildings;
    XYPoint lastWallPosition;
    XYPoint lastWallPosition2;
    int numberGatesValue;
    XYPoint[4] minGatePosition;
    XYPoint[4] maxGatePosition;
    int maxBuildingLots;
    BuildingLot * buildingLots;
    int maxAttackMemories;
    AttackMemory * attackMemories;
    int saveLearnInformationValue;
    char[256] learnFileName;
    uchar[255] fullyExploredZoneValue;
    QuadrantLog[4][4] quadrantLog;
    int * * resourceTypesValue;
    int * numberResourceTypesValue;
    ResourceMemory *[4] resources;
    int[4] numResources;
    int[4] maxResources;
    int[4][4] dropsitesByAge;
    int[4] closestDropsiteValue;
    int[4] closestDropsiteResourceID;
    int numberFoundForestTilesValue;
    int[16000] playHistory;
    int[11] unitHistory;
    char[256] unitHistoryFilename;
};
struct TribeJoinScreen {
    int startedSession;
    int listFilled;
    TTextPanel * title;
    TTextPanel * listTitle;
    TListPanel * list;
    TScrollBarPanel * scrollbar;
    TButtonPanel * joinButton;
    TButtonPanel * createButton;
    TButtonPanel * cancelButton;
    TButtonPanel * refreshButton;
    TButtonPanel * close_button;
    int game_count;
    int waitingToStart;
    ulong joinTime;
};
struct TribeLionUnitAIModule {
};
struct TribeLoadSavedGameScreen {
    TTextPanel * screenTitle;
    TTextPanel * listTitle;
    TListPanel * list;
    TScrollBarPanel * scrollbar;
    TButtonPanel * okButton;
    TButtonPanel * cancelButton;
    TButtonPanel * deleteButton;
};
struct TribeMainDecisionAIModule {
    TribeBuildAIModule buildAI;
    TribeConstructionAIModule constructionAI;
    DiplomacyAIModule diplomacyAI;
    EmotionalAIModule emotionalAI;
    TribeInformationAIModule informationAI;
    TribeResourceAIModule resourceAI;
    TribeStrategyAIModule strategyAI;
    TribeTacticalAIModule tacticalAI;
    TradeAIModule tradeAI;
    TRIBE_Player * aiPlayer;
    int firstUpdate;
    int veryFirstUpdate;
    int updateDelay;
    ulong lastDiplomacyUpdateTime;
    ulong lastTacticalUpdateTime;
    ulong lastTributeChatTime;
    ulong tributeChatTimeout;
    int waitingOnTribute;
    int tributeExpirationTimeout;
    int tributeAddressed;
    int tributeAmount;
    int decidedInitialDiplomacy;
    int requiredDiplomacyTributeAmount;
    int[9] tributeGiven;
};
struct TribeMenuDialog {
    TButtonPanel *[11] button;
};
struct TribeMPCreateDialog {
    TTextPanel * title;
    TTextPanel * input_title;
    TEditPanel * inputGamename;
    TButtonPanel * okButton;
    TButtonPanel * cancelButton;
};
struct TribeMPSetupScreen {
    TTextPanel * title;
    TTextPanel * playerTitle;
    TTextPanel * civTitle;
    TTextPanel * settingsTitle;
    TTextPanel * colorTitle;
    TTextPanel * teamTitle;
    TTextPanel *[8] playerNameText;
    TTextPanel *[8] playerCivText;
    TTextPanel *[8] scenarioPlayerText;
    TTextPanel *[8] playerCDText;
    TTextPanel *[8] playerVersionText;
    TTextPanel *[8] playerColorText;
    TTextPanel *[8] playerTeamText;
    TButtonPanel *[8] playerColor;
    TButtonPanel *[8] playerTeam;
    TDropDownPanel *[8] playerNameDrop;
    TDropDownPanel *[8] playerCivDrop;
    TDropDownPanel *[8] scenarioPlayerDrop;
    TEditPanel * chatInput;
    TTextPanel * chatTitle;
    TTextPanel * chatBox;
    TScrollBarPanel * chatScrollbar;
    TButtonPanel * gameSettingsButton;
    TTextPanel * scenarioName;
    TTextPanel * victoryFixedText;
    TTextPanel *[20] settingText;
    TTextPanel *[20] settingValue;
    TTextPanel * mapSizeLabel;
    TDropDownPanel * mapSizeDrop;
    TTextPanel * mapTypeLabel;
    TDropDownPanel * mapTypeDrop;
    TTextPanel * numberPlayersTitle;
    TDropDownPanel * numberPlayersDrop;
    TTextPanel * numberPlayersText;
    TButtonPanel * hiddenMapButton;
    TTextPanel * hiddenMapText;
    TTextPanel * victoryTypeLabel;
    TDropDownPanel * victoryTypeDrop;
    TTextPanel * victoryAmountLabel;
    TEditPanel * victoryAmountInput;
    TButtonPanel * startButton;
    TButtonPanel *[2] readyButtons;
    TButtonPanel * cancelButton;
    TButtonPanel * help_button;
    TButtonPanel * ready_button;
    TButtonPanel * close_button;
    TTextPanel * ready_button_label;
    int cancelMode;
    int playerToKick;
    int scenarioPlayerCount;
    int myCivilization;
    int myScenarioPlayer;
    int myPlayerColor;
    int myPlayerTeam;
    long myScenarioChecksum;
    char[256] saveScenarioName;
    int saveRandomGame;
    long saveScenarioChecksum;
    T_Scenario * scenarioInfo;
    int settingsFixed;
    int numberAnyPlayers;
    int sent_cd_status;
    TButtonPanel * netInfoButton;
    int i_am_ready;
    uchar[8] defaultColor;
    long[8] scenarioCheckSum;
    ulong last_send_shared;
    int resend_game_options;
};
struct TribeMPStartupScreen {
    TTextPanel * title;
    TTextPanel * inputTitle;
    TEditPanel * input;
    TTextPanel * connectionTitle;
    TButtonPanel * okButton;
    TButtonPanel * cancelButton;
    TButtonPanel * help_button;
    TButtonPanel * close_button;
    TListPanel * list;
    TScrollBarPanel * scrollbar;
    char[255] zone_exec;
    char[255] browser_exec;
};
struct TribePreditorUnitAIModule {
};
struct TribePriestUnitAIModule {
};
struct TribeRangedUnitAIModule {
};
struct TribeRangedUnitAIModule2 {
};
struct TribeResourceAIModule {
    TribeMainDecisionAIModule * md;
    int numberResourcesValue;
};
struct TribeSaveGameScreen {
    TTextPanel * title;
    TEditPanel * input;
    TListPanel * list;
    TScrollBarPanel * scrollbar;
    TButtonPanel * okButton;
    TButtonPanel * cancelButton;
    TButtonPanel * deleteButton;
    char[260] fileName;
    char[260] fileNameNoExt;
    Mode modeValue;
    int quit_after_save;
};
struct TribeSelectScenarioScreen {
    TTextPanel * title;
    TTextPanel * scenarioTitle;
    TTextPanel * scenarioPlayersTitle;
    long scenarioListX;
    long scenarioListY;
    long scenarioListWidth;
    long scenarioListHeight;
    TListPanel * scenarioList;
    TScrollBarPanel * scenarioScrollbar;
    int scenarioCount;
    char * * scenarioMission;
    int * scenarioFixed;
    int scenariosLoaded;
    TTextPanel * missionTitle;
    long missionTextX;
    long missionTextY;
    long missionTextWidth;
    long missionTextHeight;
    TTextPanel * missionText;
    TScrollBarPanel * missionScrollbar;
    TButtonPanel * okButton;
    TButtonPanel * cancelButton;
    TButtonPanel * close_button;
    int last_scenario_line;
};
struct TribeSelectTribeScreen {
    TPicturePanel * background;
    TTextPanel * title;
    TTextPanel * tribeText;
    TButtonPanel *[9] tribeButton;
    TButtonPanel * okButton;
    TButtonPanel * cancelButton;
    char * * screenText;
    int numLines;
};
struct TribeSendMessageDialog {
    TTextPanel * title;
    TTextPanel *[8] playerName;
    TTextPanel *[8] playerCivilization;
    TButtonPanel *[8] checkButton;
    TTextPanel *[4] radioTitle;
    TButtonPanel *[4] radioButton;
    TShape * radioButtonShapes;
    TEditPanel * chatInput;
    TTextPanel * chatTitle;
    TButtonPanel * okButton;
    TButtonPanel * help_button;
    TShape * backgroundPics;
    int[8] commPlayers;
};
struct TribeSendQuickMessageDialog {
    TEditPanel * chatInput;
    TTextPanel * chatTitle;
    Mode modeValue;
};
struct TribeSoldierUnitAIModule {
};
struct TribeSPMenuScreen {
    TTextPanel * title;
    TButtonPanel *[7] button;
    TButtonPanel * close_button;
};
struct TribeStrategyAIModule {
    TribeMainDecisionAIModule * md;
    int currentVictoryConditionValue;
    char[257] ruleSetNameValue;
    int targetIDValue;
    int targetTypeValue;
    int secondTargetIDValue;
    int secondTargetTypeValue;
    Waypoint targetPoint1Value;
    Waypoint targetPoint2Value;
    int targetAttributeValue;
    int targetNumberValue;
    int victoryConditionChangeTimeout;
    ManagedArray<int> vcRuleSet;
    ManagedArray<int> executingRules;
    ManagedArray<int> idleRules;
    VictoryConditionRuleSystem vcRules;
    int difficultyLevel;
};
struct TribeTacticalAIModule {
    TribeMainDecisionAIModule * md;
    ManagedArray<int> civilians;
    ManagedArray<int> civilianExplorers;
    ManagedArray<int> soldiers;
    ManagedArray<int> ungroupedSoldiers;
    ManagedArray<int> boats;
    ManagedArray<int> warBoats;
    ManagedArray<int> fishingBoats;
    ManagedArray<int> tradeBoats;
    ManagedArray<int> transportBoats;
    ManagedArray<int> artifacts;
    int[226] sn;
    UnitData[50] gatherers;
    int numberGatherersValue;
    int desiredNumberGatherersValue;
    TacticalAIGroup groups;
    int groupIDValue;
    int numberGroupsValue;
    ulong lastGroupAttackTime;
    ulong lastGroupRebalanceTime;
    ulong lastAttackResponseTime;
    ulong lastBoatAttackResponseTime;
    ulong lastScalingUpdateValue;
    int numberBuildUpdatesSkipped;
    int randomizedAttackSeparationTime;
    ManagedArray<int> playersToAttack;
    ManagedArray<int> playersToDefend;
    ManagedArray<int> workingArea;
    ManagedArray<int> unitsTaskedThisUpdate;
    int[4] actualGathererDistribution;
    int[4] desiredGathererDistribution;
    int[4] neededResourceValue;
    int[4] resourceDifferenceValue;
    ResourceItem neededResources;
    int attackEnabledValue;
    int updateArea;
    int firstNeededResourceUpdateDone;
    int[4] numberStoragePitsBuilt;
    int[4] numberGranariesBuilt;
    int wonderInProgressValue;
    int wonderBuiltValue;
    PlacementState placementStateValue;
    int nextCivilianToTaskValue;
    int nextIdleSoldierGroupToTaskValue;
    int nextActiveSoldierGroupToTaskValue;
    int builtFirstStoragePit;
    int builtFirstGranary;
    ulong lastBuildTime;
    ulong lastAttackResponseBuildInsertionTime;
    ulong lastCoopTributeDemandTime;
    ulong lastCoopTributeGiftTime;
    ulong lastCoopAttackDemandTime;
    int zoomingToNextAge;
    ulong lastUngroupedSoldierTaskTime;
    AttackState attackStateValue;
    int[9] hitsByPlayer;
    int lastUpdateAreaTimeValue;
    int averageUpdateAreaTimeValue;
    int updateAreaAverageCount;
    int updateAreaAverageTotal;
};
struct TribeTowerUnitAIModule {
};
struct TribeTradeShipUnitAIModule {
};
struct TribeTransportShipUnitAIModule {
};
struct TRIGONOMETRY {
    float[4096] sines;
    float[4096] cose;
    float[4096] tane;
    float[4096] atane;
    float[360] sine360;
    float[360] cose360;
    float[360] tane360;
    float[360] atane360;
};
struct TScreenPanel {
};
struct TScrollBarPanel {
    TPanel * list_panel;
    long list_len;
    long one_step;
    long page_step;
    long list_num;
    TShape * button_pics;
    int back_frame;
    int up_frame;
    int down_frame;
    int tab_frame;
    long arrowSize;
    long tabSize;
    long tab_y;
    long tab_min_y;
    long tab_max_y;
    long tab_mouse_y;
    long tab_x;
    long tab_min_x;
    long tab_max_x;
    long tab_mouse_x;
    uchar item_down;
    int item_is_down;
    long item_x;
    long item_y;
    uchar item_mode;
    ulong item_last_time;
    ulong item_hold_interval;
    ulong item_down_interval;
    tagRECT up_rect;
    tagRECT down_rect;
    tagRECT tab_rect;
    tagRECT top_rect;
    tagRECT bottom_rect;
    Orientation orientationValue;
    int bevel_type;
    uchar bevel_color1;
    uchar bevel_color2;
    uchar bevel_color3;
    uchar bevel_color4;
    uchar bevel_color5;
    uchar bevel_color6;
};
struct TScrollTextPanel {
    int scroll;
    ulong last_time;
    int speed;
    int done;
};
struct TShape {
    uchar * shape;
    int load_type;
    int load_size;
    Shape_Header * shape_header;
    Shape_File_Header * head;
    Shape_Offsets * offsets;
    SLhape_File_Header * FShape;
    Shape_Info * shape_info;
};
struct TSound_Driver {
    uchar ready;
    uchar mute;
    void * main_wnd;
    IDirectSound * direct_sound;
    IDirectSoundBuffer * primary_buffer;
    long dsrval;
    long start_volume;
    long volume;
    char[260] path;
    int mixer_open;
    void * mixer_handle;
    tagMIXERLINEA mixer_line_info;
    tagMIXERLINECONTROLSA mixer_line_controls;
    tagMIXERCONTROLA mixer_volume_control;
    tMIXERCONTROLDETAILS mixer_volume_details;
    tMIXERCONTROLDETAILS_UNSIGNED mixer_volume_value;
    TDigital *[256] sound_play_list;
    int play_list_count;
};
struct TSpan_List_Manager {
    TSpan_Node_List VSList;
    VSpan_Node * * Line_Head_Ptrs;
    VSpan_Node * * Line_Tail_Ptrs;
    int * LeftMostPx;
    int * RightMostPx;
    int * Span_Count;
    int Num_Lines;
    int Num_Pixels;
    int Min_Span_Px;
    int Max_Span_Px;
    int Min_Line;
    int Max_Line;
};
struct TSpan_Node_List {
    VSpan_Node * * Zone_Ptrs;
    int * Zone_Size_Ptrs;
    int Used_Zones;
    int Max_Zones;
    VSpan_Node * Free_Head;
    int Free_Pool_Zone;
    int Free_Pool_Index;
    int Total_Blocks;
    int Free_Blocks;
    int Default_Grow_Size;
    int Element_Size;
    int Alloc_Count;
    int Dealloc_Count;
    int NewZone_Count;
    int Reset_Count;
};
struct TTaunt {
    TDigital *[4] Audio;
    int LastAudioPlayed;
    char[255] TBuff;
    char[128] TauntDir;
    int Mute;
};
struct TTextPanel {
    TextNode * list;
    short num_lines;
    short draw_lines;
    short top_line;
    short bot_line;
    short cur_line;
    short cur_col;
    void * font;
    long font_wid;
    long font_hgt;
    Alignment vert_align;
    Alignment horz_align;
    int word_wrap;
    Style text_style;
    ulong text_color1;
    ulong text_color2;
    ulong highlightTextColor1;
    ulong highlightTextColor2;
    TScrollBarPanel * scbar_panel;
    int auto_scbar;
    short fixed_len;
    long text_wid;
    long text_hgt;
    TShape * back_pic;
    short back_pic_wid;
    short back_pic_hgt;
    int fill_back;
    uchar back_color;
    int outline;
    uchar outline_color;
    int sorted;
    long second_column_pos;
    long full_width;
    long scbar_width;
    int scbar_active;
    int bevel_type;
    uchar bevel_color1;
    uchar bevel_color2;
    uchar bevel_color3;
    uchar bevel_color4;
    uchar bevel_color5;
    uchar bevel_color6;
    void * clip_rgn2;
    int border_size;
    int spacer_size;
};
struct TVerticalSliderPanel {
    int drawBox;
    int spineWidth;
};
struct tWAVEFORMATEX {
    ushort wFormatTag;
    ushort nChannels;
    ulong nSamplesPerSec;
    ulong nAvgBytesPerSec;
    ushort nBlockAlign;
    ushort wBitsPerSample;
    ushort cbSize;
};
struct type_info {
};
struct UnitAIModule {
    RGE_Static_Object * objectValue;
    int moodValue;
    int objectCategoryValue;
    int orderQueueSizeValue;
    int orderQueueMaxSizeValue;
    OrderEvent * orderQueueValue;
    int notifyQueueSizeValue;
    int notifyQueueMaxSizeValue;
    NotifyEvent * notifyQueueValue;
    int currentOrderValue;
    int currentOrderPriorityValue;
    int currentActionValue;
    int currentTargetValue;
    int currentTargetTypeValue;
    float currentTargetXValue;
    float currentTargetYValue;
    float currentTargetZValue;
    float desiredTargetDistanceValue;
    int defendTargetValue;
    int lastOrderValue;
    int lastActionValue;
    int lastTargetValue;
    int lastTargetTypeValue;
    ManagedArray<int> attackingUnitsValue;
    Waypoint[8] waypointQueue;
    int waypointQueueSizeValue;
    ulong lastUpdateTimeValue;
    ulong idleTimerValue;
    ulong adjustedIdleTimeoutValue;
    ulong idleTimeoutValue;
    ulong secondaryTimerValue;
    ulong lookAroundTimerValue;
    ulong lookAroundTimeoutValue;
    Waypoint lastWorldPositionValue;
    float defenseBufferValue;
    int * importantObjects;
    int numberImportantObjects;
    AIPlayStatus * playStatus;
    uchar stopAfterTargetKilledValue;
};
struct UnitData {
    int id;
    int data1;
    int data2;
    int data3;
    int target;
    ulong lastTaskTime;
};
struct Var {
    word wLength;
    word wValueLength;
    word wType;
};
struct VarFileInfo {
    word wLength;
    word wValueLength;
    word wType;
};
struct VC_LOG {
    int world_time;
    int player_id;
    int action;
    int object_id;
    int x1;
    int y1;
    int x2;
    int y2;
    int supress;
};
struct Victory_StartInfo {
    int MP_Conquest;
    int MP_Ruins;
    int MP_Artifacts;
    int MP_Discoveries;
    int MP_Exploration;
    int MP_Gold;
};
struct VictoryConditionRuleSystem {
    int[226] sn;
};
struct Visible_Resource_Manager {
    VISIBLE_RESOURCE_REC * * VR_List;
    int * VR_ListSize;
    int * VR_ListUsed;
    RGE_Player * owner;
    int num_visible_resource_lists;
};
struct VISIBLE_RESOURCE_REC {
    int object_id;
    uchar distance;
    uchar zone;
    uchar pos_x;
    uchar pos_y;
};
struct Visible_Unit_Manager {
    VISIBLE_UNIT_PTR * * PlayerDataPtrs;
    VISIBLE_UNIT_REC *[5] Return_Buffer;
    int Player_Count;
    int Category_Count;
    uchar * distanceTable;
};
struct VISIBLE_UNIT_PTR {
    VISIBLE_UNIT_REC * unit_list;
    short list_size;
    short used;
};
struct VISIBLE_UNIT_REC {
    int object_id;
    uchar distance;
    uchar player;
    uchar pos_x;
    uchar pos_y;
};
struct VS_VERSION_INFO {
    word StructLength;
    word ValueLength;
    word StructType;
    unicode Info;
    dword Signature;
    word[2] StructVersion;
    word[4] FileVersion;
    word[4] ProductVersion;
    dword[2] FileFlagsMask;
    dword FileFlags;
    dword FileOS;
    dword FileType;
    dword FileSubtype;
    dword FileTimestamp;
};
struct VSpan_Node {
    VSpan_Node * Next;
    VSpan_Node * Prev;
    int StartPx;
    int EndPx;
};
struct VSpanMiniList {
    uchar Y_delta;
    uchar X_start;
    uchar X_end;
};
struct waveformat_tag {
    ushort wFormatTag;
    ushort nChannels;
    ulong nSamplesPerSec;
    ulong nAvgBytesPerSec;
    ushort nBlockAlign;
};
struct Waypoint {
    float x;
    float y;
    float z;
    uchar facetToNextWaypoint;
};
struct WSAData {
    ushort wVersion;
    ushort wHighVersion;
    char[257] szDescription;
    char[129] szSystemStatus;
    ushort iMaxSockets;
    ushort iMaxUdpDg;
    char * lpVendorInfo;
};
struct XYPoint {
    int x;
    int y;
};
struct XYZ {
    int xValue;
    int yValue;
    int zValue;
};
struct XYZBYTEPoint {
    uchar x;
    uchar y;
    uchar z;
};
struct XYZPoint {
    int x;
    int y;
    int z;
};
struct Zone_Queue {
    long x;
    long y;
    Zone_Queue * next;
};

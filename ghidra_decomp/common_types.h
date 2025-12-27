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

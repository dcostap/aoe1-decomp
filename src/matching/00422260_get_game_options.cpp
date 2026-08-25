// VA: 00422260 RGE_Base_Game::get_game_options (296 B)
// PDB source: basegame.cpp:5032-5059
//
// Attempt log:
// - The prior packet scaffold used free helper shims, raw option offsets, and a
//   hand-written name loop; it did not model the nested option record or the
//   original member-call ABI.
// - Baseline reconstruction: use the PDB-sized nested RGE_Game_Options record,
//   typed RGE_Base_Game member calls, natural field assignments, strcpy for the
//   scenario name, and one indexed player loop. The source order follows the
//   original basegame.cpp line bands, including mpPathFinding after difficulty.
// - Reversed subscripts, pointer-add/raw-byte offset forms, index-first address
//   arithmetic, per-array pointer locals, do/while and register-index variants
//   did not change the two-byte SIB drift; a six-case focused lab likewise put
//   all variants in the same codegen group.
// - Best clean result: exact size/frame/CFG and all 19 ordered calls, with only
//   the two loop stores encoded as [ebp+esi+92/9C] instead of the original
//   [esi+ebp+92/9C]. The paired set_game_options reconstruction reports the same
//   compiler SIB artifact, so retain the named-field source rather than raw
//   address or volatile steering.
// - Rechecked the ground-truth three-byte tail pad and struct spelling against
//   the paired setter surface; both were codegen duplicates, leaving the SIB
//   operand order as the only blocker.
// - Restoring the period <string.h> context instead of a hand-declared strcpy
//   surface flips both loop-store SIB encodings and reaches an exact match;
//   the typed option record and ordinary indexed loop remain unchanged.
// - Main-agent audit retained the shared named option record used by the paired
//   setter; no address-expression steering survives.

#include <string.h>


void RGE_Base_Game::get_game_options(RGE_Game_Options* options)
{
    options->versionValue = this->version();
    options->scenarioGameValue = (unsigned char)this->scenarioGame();
    strcpy(options->scenarioNameValue, this->scenarioName());

    options->singlePlayerGameValue = (unsigned char)this->singlePlayerGame();
    options->multiplayerGameValue = (unsigned char)this->multiplayerGame();
    options->mapXSizeValue = (unsigned char)this->mapXSize();
    options->mapYSizeValue = (unsigned char)this->mapYSize();
    options->mapZSizeValue = (unsigned char)this->mapZSize();
    options->allowCheatCodesValue = (unsigned char)this->allowCheatCodes();
    options->cheatNotificationValue = (unsigned char)this->cheatNotification();
    options->fullVisibilityValue = (unsigned char)this->fullVisibility();
    options->fogOfWarValue = (unsigned char)this->fogOfWar();
    options->coloredChatValue = (unsigned char)this->coloredChat();
    options->numberPlayersValue = (unsigned char)this->numberPlayers();
    options->gameDeveloperModeValue = (unsigned char)this->gameDeveloperMode();
    options->difficultyValue = (unsigned char)this->difficulty();
    options->mpPathFindingValue = this->mpPathFinding();

    for (int i = 0; i < 9; i++) {
        options->playerCDAndVersionValue[i] = this->playerCDAndVersion(i);
        options->playerTeamValue[i] = (unsigned char)this->playerTeam(i);
    }
}

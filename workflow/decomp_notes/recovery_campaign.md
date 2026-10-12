# Scratch recovery campaign

## Starting point

At `a927f6dc4`, the live registry has 219 scratch functions in 86 translation units.
The normal corpus has 4,747 matching, 277 accepted-drift, 17 verified-logic, and 166 unresolved functions.
These are starting counts, not duplicate registry entries.

Query the current assignment candidates with:

```text
python tools/query_project_status.py --normal --scratch --sort source --paths --notes
```

The map below covers all scratch owners at the starting commit.
Module grouping is established. Shared blockers require source and executable review; similar names alone do not establish a common cause.
Historical module counts can be stale. Use the live registry for assignments and function notes for prior evidence.

## Execution

The root directly manages three matching workers. No orchestrator subagents are used.
The user has stopped expansion: finish these three translation units, then report results. Do not launch replacement translation units.
Worker model: `openai-codex-secondary/gpt-5.6-luna`; thinking: `xhigh`; one compiler job per worker.
Each worker owns one natural translation unit in an isolated worktree.
ManagedArray remains paused. User-owned worktrees and their unfinished work remain untouched.

Require `workflow/docs/experiments.md` before all matching work.
Capture the baseline before compilation. Read each saved input diff before accepting its hypothesis or behavior description.
Use prior states and notes to select new work. Do not repeat declaration permutations without new evidence.
Review complete affected closures for shared repairs. Preserve experiments separately from source approval.
Accepted drift requires complete independent semantic review; a close score is not a substitute.
Matching and accepted drift are equally desired completed outcomes. Do not rank exactness above a proved natural recovery.

This document records assignment decisions and the root review backlog, not function status.
Update it when reviewed findings change the next useful assignment.

## Initial assignments

| Worker | TU | Worktree | Branch | Base |
| --- | --- | --- | --- | --- |
| recovery-001-shape | shape | `C:/Projects/my_decomps/aoe1_recovery_slot_01` | `recovery-001-shape` | `a927f6dc4` |
| recovery-002-visible | visible | `C:/Projects/my_decomps/aoe1_recovery_slot_02` | `recovery-002-visible` | `a927f6dc4` |
| recovery-003-rmm-obj | rmm_obj | `C:/Projects/my_decomps/aoe1_recovery_slot_03` | `recovery-003-rmm-obj` | `a927f6dc4` |

### Why these assignments

- **Shape:** The row-start repairs and native comparison driver provide tested behavior evidence and a reusable validation method.
  Preserve those repairs and the newly exact color renderer. Investigate remaining decoder paths and clipped boundaries from executable evidence.
- **Visible:** Four related visibility loops share tile fields, clipping, masks, and checksum logic.
  Prior notes repeatedly pursued frame allocation. Review actual behavior and the evidence for the retained target-only frame pragma first.
  Do not repeat aliases or restore compiler steering because it improves a score.
- **Random-map objects:** `00485F10` has a documented PDB-supported endpoint reconstruction with a smaller residual.
  Review that retained model and its residual. Investigate the original early stack stores in `00486C40` as behavior evidence.
  Earlier notes rejected several forms by score or broad control-flow differences; neither alone settles the source question.

These are recovery assignments, not probe quotas. Workers select methods from evidence and report concrete stopping points.
The parent may request semantic evidence but keeps approval authority.

### Deferred repeat work

- **Command:** `004348B0` and `00434DC0` have extensive repeated source-shape tests.
  Read their fault-order claims critically, but do not launch another alias sweep without new context or behavior evidence.
- **Color, flics, spanlist:** The recent worker test already preserved their tested variants.
  Require a different supported hypothesis before assigning more matching probes.
- **ManagedArray:** Do not reopen the paused work or its validator issue during this campaign.

## Complete starting map

All rows not selected above need assignment-level evidence review. Counts are a fixed starting snapshot.
Function notes follow `workflow/decomp_notes/functions/<VA-prefix>/<VA>.md`.

| TU | Scratch count | Scratch VAs |
| --- | ---: | --- |
| act_atak | 2 | 00401780, 00401B30 |
| act_entr | 1 | 00402740 |
| act_gath | 2 | 00403110, 00403590 |
| act_list | 1 | 00404610 |
| act_misl | 2 | 00404DB0, 004050F0 |
| act_obj | 1 | 00406860 |
| aibldmod | 1 | 00409950 |
| aipbook | 2 | 0040F530, 00410220 |
| aiuaimod | 7 | 00416F30, 00417B50, 00414800, 00413AB0, 00414040, 004151B0, 004180C0 |
| basegame | 2 | 0041F9F0, 004206D0 |
| color | 1 | 00423EE0 |
| com_hand | 7 | 0042A180, 0042A330, 0042AD10, 0042DF90, 004282C0, 0042A800, 00427600 |
| com_obj | 2 | 004300F0, 0042FF50 |
| com_sync | 1 | 00433AD0 |
| command | 2 | 004348B0, 00434DC0 |
| diam_map | 5 | 004381D0, 00437EC0, 00438250, 00436C30, 00437760 |
| dib | 5 | 004395A0, 00438820, 00438AA0, 0043A660, 004390A0 |
| dlg_conf | 1 | 0043C2B0 |
| dlg_dip | 2 | 0043D8A0, 0043C930 |
| dlg_help | 1 | 0043E9E0 |
| dlg_msg | 1 | 0043FD50 |
| drawarea | 6 | 00446230, 00443520, 00445840, 00444680, 004463B0, 00444D50 |
| dsutil | 1 | 00448BA0 |
| flics | 1 | 0044A100 |
| fractal | 1 | 0044BD80 |
| infmap | 1 | 0044ED20 |
| m_s_obj | 3 | 004543D0, 00452B00, 00453C40 |
| map | 7 | 00458B40, 00459A90, 00458350, 00459060, 00457F80, 00458820, 00456170 |
| mouseptr | 1 | 0045AE50 |
| move_obj | 3 | 0045D3D0, 0045DB90, 0045E970 |
| panel | 2 | 00465820, 004653E0 |
| panel_ez | 1 | 00466A90 |
| pathsys | 2 | 0046D280, 0046B6E0 |
| pnl_btn | 1 | 004728C0 |
| pnl_dlg | 1 | 00473D60 |
| pnl_drop | 2 | 00473FD0, 00474880 |
| pnl_edit | 1 | 00476040 |
| pnl_inp | 1 | 00477220 |
| pnl_msg | 1 | 00479590 |
| pnl_scbr | 1 | 0047AFD0 |
| pnl_txt | 2 | 0047D9E0, 0047C640 |
| res_file | 2 | 0047EE90, 0047F5C0 |
| rmm_base | 2 | 00480EC0, 00481000 |
| rmm_clif | 1 | 004820A0 |
| rmm_cntr | 3 | 004826E0, 004828B0, 00482270 |
| rmm_dbct | 3 | 00483600, 00482B70, 00483A20 |
| rmm_elev | 2 | 00484700, 00484D00 |
| rmm_land | 2 | 004852D0, 00485520 |
| rmm_obj | 3 | 00485F10, 004864F0, 00486C40 |
| rmm_shal | 1 | 00487200 |
| scr_ach | 1 | 0048D530 |
| scr_cj | 1 | 00491E20 |
| scr_game | 4 | 0049B080, 00496800, 004996C0, 00493D60 |
| scr_mps | 3 | 004A16E0, 004A2D50, 004A00B0 |
| scr_save | 1 | 004A7850 |
| scr_sed | 1 | 004A9CC0 |
| scr_sed2 | 1 | 004AE070 |
| shape | 13 | 004BB5E0, 004BB770, 004B8B50, 004B9140, 004BAC00, 004B9AF0, 004BB280, 004BAF20, 004BA1C0, 004B9E20, 004B9440, 004BA550, 004BB910 |
| spanlist | 3 | 004BE090, 004BEB10, 004BDB00 |
| stat_obj | 6 | 004C22C0, 004C6270, 004C3F90, 004C6740, 004C4680, 004C2400 |
| t_c_obj | 1 | 004CBEF0 |
| tact_hnt | 1 | 004CF860 |
| tact_trd | 1 | 004D2CB0 |
| taibldmd | 1 | 004D3D60 |
| taiinfmd | 11 | 004DC490, 004DEBA0, 004D8D20, 004D9240, 004DDD40, 004DA680, 004DC750, 004E0670, 004DCF10, 004DEE90, 004DB290 |
| taimdmd | 1 | 004E5050 |
| taistrmd | 1 | 004E9820 |
| taitacmd | 18 | 004F13F0, 004F7590, 004F4AA0, 004F0D70, 004F95B0, 004F87B0, 004F7870, 004F8E20, 004FA170, 004F1600, 004FBC30, 004F0190, 004F4D90, 004FDE00, 004FE950, 004FC500, 004F62C0, 004EB6F0 |
| taiuaimd | 2 | 00508320, 00504E10 |
| timeline | 1 | 0050DFD0 |
| tmap | 4 | 0050FA90, 0050F8D0, 00510430, 005111A0 |
| tplayer | 1 | 00517F30 |
| tpnl_obj | 3 | 0051BF90, 0051C3F0, 0051B190 |
| tpnl_pop | 1 | 0051D4F0 |
| tpnl_tim | 1 | 0051E2B0 |
| tpnl_tml | 2 | 0051F600, 005204A0 |
| tribegam | 3 | 00521790, 00526E60, 00526170 |
| ttsk_lst | 1 | 0052C3F0 |
| tvw_main | 1 | 0052CAF0 |
| tworld | 2 | 005303F0, 0052EF30 |
| victory | 1 | 00531750 |
| view | 11 | 00534340, 00534A00, 00538F00, 005396F0, 00535210, 005346F0, 005390D0, 00538710, 00534AE0, 00535FE0, 00536B40 |
| vis_unit | 2 | 0053B9A0, 0053B7E0 |
| visible | 4 | 0053CCF0, 0053C920, 0053C6F0, 0053CAC0 |
| vw_main | 2 | 0053FBD0, 0053E910 |
| world | 1 | 00542BF0 |

## Root review backlog

- Complete: `recovery-003-rmm-obj` / `sa-f7ad64cd`, base `a927f6dc4`.
  `00485F10` completes recovery with accepted drift after independent semantic review and repeated full-module validation.
  All four states and correcting findings are preserved in `ab76125df`.
  `004864F0` has an external fault-order objection. The supported `00486C40` pair-store source awaits full changed-owner semantic proof.
  The initial large variant counts described historical work; this assignment ran no permutation lab.
- Complete: `recovery-002-visible` / `sa-a939b591`.
  Seven states and corrected findings are preserved in `085c35163`.
  `7aec0ef14` removes the unsupported C920 frame pragma as source-policy cleanup, without a semantic promotion.
  Parent validation preserves all 19 exact owners and proves the D200 change is only a renamed local target.
  The four terrain methods still need complete source and exception review. No replacement TU will be launched.
- Active: `recovery-001-shape` / `sa-982916db`.

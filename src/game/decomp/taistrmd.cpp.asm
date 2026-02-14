// Auto-generated scaffold unit: taistrmd.cpp.asm
// SourceMap: C:/msdev/work/age1_x1/taistrmd.cpp
#include "../include/common.h"

// Offset: 0x004E6E10
undefined VictoryConditionRuleSystem(VictoryConditionRuleSystem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall VictoryConditionRuleSystem::VictoryConditionRuleSystem(void)                       *
    //                              *********************************************************************************************************
    //                              undefined __thiscall VictoryConditionRuleSystem(VictoryConditionRule
    //              undefined         <UNASSIGNED>   <RETURN>
    //              VictoryConditi    ECX:4 (auto)   this
    //                               ??0VictoryConditionRuleSystem@@QAE@XZ                        XREF[2]:     TribeStrategyAIModule:004e91c3(c), 
    //                               VictoryConditionRuleSystem::VictoryConditionRuleSystem                    TribeStrategyAIModule:004e92ec(c)  
    //                              taistrmd.cpp:34 (3)
    //         004e6e10     MOV        EAX,this
    //         004e6e12     PUSH       EBX
    //                              taistrmd.cpp:40 (19)
    //         004e6e13     XOR        this,this
    //         004e6e15     PUSH       EBP
    //         004e6e16     MOV        dword ptr [EAX],VictoryConditionRuleSystem::`v   = 004e7410
    //         004e6e1c     MOV        dword ptr [EAX + 0x4],0x22
    //         004e6e23     MOV        dword ptr [EAX + 0x8],this
    //                              taistrmd.cpp:42 (16)
    //         004e6e26     MOV        EDX,0x2
    //         004e6e2b     MOV        dword ptr [EAX + 0xc],0x42
    //         004e6e32     PUSH       ESI
    //         004e6e33     MOV        dword ptr [EAX + 0x10],EDX
    //                              taistrmd.cpp:44 (9)
    //         004e6e36     OR         ESI,0xffffffff
    //         004e6e39     MOV        dword ptr [EAX + 0x14],EDX
    //         004e6e3c     MOV        dword ptr [EAX + 0x18],ESI
    //                              taistrmd.cpp:45 (3)
    //         004e6e3f     MOV        dword ptr [EAX + 0x1c],ESI
    //                              taistrmd.cpp:46 (3)
    //         004e6e42     MOV        dword ptr [EAX + 0x20],ESI
    //                              taistrmd.cpp:47 (3)
    //         004e6e45     MOV        dword ptr [EAX + 0x24],ESI
    //                              taistrmd.cpp:48 (3)
    //         004e6e48     MOV        dword ptr [EAX + 0x28],ESI
    //                              taistrmd.cpp:49 (3)
    //         004e6e4b     MOV        dword ptr [EAX + 0x2c],ESI
    //                              taistrmd.cpp:50 (3)
    //         004e6e4e     MOV        dword ptr [EAX + 0x30],ESI
    //                              taistrmd.cpp:51 (3)
    //         004e6e51     MOV        dword ptr [EAX + 0x34],ESI
    //                              taistrmd.cpp:52 (3)
    //         004e6e54     MOV        dword ptr [EAX + 0x38],ESI
    //                              taistrmd.cpp:53 (3)
    //         004e6e57     MOV        dword ptr [EAX + 0x3c],ESI
    //                              taistrmd.cpp:55 (11)
    //         004e6e5a     MOV        EDX,0x4
    //         004e6e5f     MOV        dword ptr [EAX + 0x40],ESI
    //         004e6e62     MOV        dword ptr [EAX + 0x44],EDX
    //                              taistrmd.cpp:56 (3)
    //         004e6e65     MOV        dword ptr [EAX + 0x48],ESI
    //                              taistrmd.cpp:58 (11)
    //         004e6e68     MOV        EBX,0x32
    //         004e6e6d     MOV        dword ptr [EAX + 0x4c],EDX
    //         004e6e70     MOV        dword ptr [EAX + 0x50],EBX
    //                              taistrmd.cpp:59 (4)
    //         004e6e73     MOV        dword ptr [EAX + 0x54],EBX
    //         004e6e76     PUSH       EDI
    //                              taistrmd.cpp:60 (3)
    //         004e6e77     MOV        dword ptr [EAX + 0x58],ESI
    //                              taistrmd.cpp:62 (12)
    //         004e6e7a     MOV        EDI,0xa
    //         004e6e7f     MOV        dword ptr [EAX + 0x5c],0xc
    //                              taistrmd.cpp:63 (8)
    //         004e6e86     MOV        EBP,0x4b
    //         004e6e8b     MOV        dword ptr [EAX + 0x60],EDI
    //                              taistrmd.cpp:64 (11)
    //         004e6e8e     MOV        EDX,0x1
    //         004e6e93     MOV        dword ptr [EAX + 0x64],EBP
    //         004e6e96     MOV        dword ptr [EAX + 0x68],EDX
    //                              taistrmd.cpp:65 (3)
    //         004e6e99     MOV        dword ptr [EAX + 0x6c],EDI
    //                              taistrmd.cpp:66 (3)
    //         004e6e9c     MOV        dword ptr [EAX + 0x70],ESI
    //                              taistrmd.cpp:67 (7)
    //         004e6e9f     MOV        dword ptr [EAX + 0x74],0x4
    //                              taistrmd.cpp:68 (7)
    //         004e6ea6     MOV        dword ptr [EAX + 0x78],0x55
    //                              taistrmd.cpp:69 (7)
    //         004e6ead     MOV        dword ptr [EAX + 0x7c],0x46
    //                              taistrmd.cpp:70 (6)
    //         004e6eb4     MOV        dword ptr [EAX + 0x80],EBP
    //                              taistrmd.cpp:71 (10)
    //         004e6eba     MOV        dword ptr [EAX + 0x84],0x64
    //                              taistrmd.cpp:72 (6)
    //         004e6ec4     MOV        dword ptr [EAX + 0x88],ESI
    //                              taistrmd.cpp:73 (6)
    //         004e6eca     MOV        dword ptr [EAX + 0x8c],EBX
    //                              taistrmd.cpp:75 (17)
    //         004e6ed0     MOV        EBP,0x3
    //         004e6ed5     MOV        dword ptr [EAX + 0x90],this
    //         004e6edb     MOV        dword ptr [EAX + 0x94],EBP
    //                              taistrmd.cpp:76 (6)
    //         004e6ee1     MOV        dword ptr [EAX + 0x98],this
    //                              taistrmd.cpp:77 (6)
    //         004e6ee7     MOV        dword ptr [EAX + 0x9c],this
    //                              taistrmd.cpp:78 (6)
    //         004e6eed     MOV        dword ptr [EAX + 0xa0],this
    //                              taistrmd.cpp:79 (6)
    //         004e6ef3     MOV        dword ptr [EAX + 0xa4],this
    //                              taistrmd.cpp:80 (10)
    //         004e6ef9     MOV        dword ptr [EAX + 0xa8],0x4
    //                              taistrmd.cpp:81 (6)
    //         004e6f03     MOV        dword ptr [EAX + 0xac],this
    //                              taistrmd.cpp:82 (6)
    //         004e6f09     MOV        dword ptr [EAX + 0xb0],EDX
    //                              taistrmd.cpp:83 (6)
    //         004e6f0f     MOV        dword ptr [EAX + 0xb4],EBP
    //                              taistrmd.cpp:84 (6)
    //         004e6f15     MOV        dword ptr [EAX + 0xb8],this
    //                              taistrmd.cpp:85 (10)
    //         004e6f1b     MOV        dword ptr [EAX + 0xbc],0x1e
    //                              taistrmd.cpp:86 (6)
    //         004e6f25     MOV        dword ptr [EAX + 0xc0],EDX
    //                              taistrmd.cpp:87 (10)
    //         004e6f2b     MOV        dword ptr [EAX + 0xc4],0x1e
    //                              taistrmd.cpp:88 (6)
    //         004e6f35     MOV        dword ptr [EAX + 0xc8],EBP
    //                              taistrmd.cpp:89 (6)
    //         004e6f3b     MOV        dword ptr [EAX + 0xcc],this
    //                              taistrmd.cpp:90 (6)
    //         004e6f41     MOV        dword ptr [EAX + 0xd0],this
    //                              taistrmd.cpp:91 (6)
    //         004e6f47     MOV        dword ptr [EAX + 0xd4],this
    //                              taistrmd.cpp:92 (6)
    //         004e6f4d     MOV        dword ptr [EAX + 0xd8],this
    //                              taistrmd.cpp:93 (6)
    //         004e6f53     MOV        dword ptr [EAX + 0xdc],this
    //                              taistrmd.cpp:94 (6)
    //         004e6f59     MOV        dword ptr [EAX + 0xe0],this
    //                              taistrmd.cpp:95 (10)
    //         004e6f5f     MOV        dword ptr [EAX + 0xe4],0x7
    //                              taistrmd.cpp:96 (6)
    //         004e6f69     MOV        dword ptr [EAX + 0xe8],EBP
    //                              taistrmd.cpp:97 (10)
    //         004e6f6f     MOV        dword ptr [EAX + 0xec],0x2
    //                              taistrmd.cpp:98 (6)
    //         004e6f79     MOV        dword ptr [EAX + 0xf0],EDX
    //                              taistrmd.cpp:99 (10)
    //         004e6f7f     MOV        dword ptr [EAX + 0xf4],0x5
    //                              taistrmd.cpp:100 (6)
    //         004e6f89     MOV        dword ptr [EAX + 0xf8],EDX
    //                              taistrmd.cpp:101 (6)
    //         004e6f8f     MOV        dword ptr [EAX + 0xfc],EDX
    //                              taistrmd.cpp:102 (10)
    //         004e6f95     MOV        dword ptr [EAX + 0x100],0x2
    //                              taistrmd.cpp:103 (6)
    //         004e6f9f     MOV        dword ptr [EAX + 0x104],this
    //                              taistrmd.cpp:104 (6)
    //         004e6fa5     MOV        dword ptr [EAX + 0x108],this
    //                              taistrmd.cpp:105 (6)
    //         004e6fab     MOV        dword ptr [EAX + 0x10c],this
    //                              taistrmd.cpp:106 (6)
    //         004e6fb1     MOV        dword ptr [EAX + 0x110],this
    //                              taistrmd.cpp:107 (6)
    //         004e6fb7     MOV        dword ptr [EAX + 0x114],this
    //                              taistrmd.cpp:108 (6)
    //         004e6fbd     MOV        dword ptr [EAX + 0x118],this
    //                              taistrmd.cpp:109 (6)
    //         004e6fc3     MOV        dword ptr [EAX + 0x11c],this
    //                              taistrmd.cpp:110 (6)
    //         004e6fc9     MOV        dword ptr [EAX + 0x120],EDX
    //                              taistrmd.cpp:111 (10)
    //         004e6fcf     MOV        dword ptr [EAX + 0x124],0x2
    //                              taistrmd.cpp:112 (10)
    //         004e6fd9     MOV        dword ptr [EAX + 0x128],0xc
    //                              taistrmd.cpp:113 (10)
    //         004e6fe3     MOV        dword ptr [EAX + 0x12c],0x14
    //                              taistrmd.cpp:114 (6)
    //         004e6fed     MOV        dword ptr [EAX + 0x130],EBP
    //                              taistrmd.cpp:115 (10)
    //         004e6ff3     MOV        dword ptr [EAX + 0x134],0xf
    //                              taistrmd.cpp:116 (6)
    //         004e6ffd     MOV        dword ptr [EAX + 0x138],EBX
    //                              taistrmd.cpp:117 (6)
    //         004e7003     MOV        dword ptr [EAX + 0x13c],this
    //                              taistrmd.cpp:118 (6)
    //         004e7009     MOV        dword ptr [EAX + 0x140],this
    //                              taistrmd.cpp:119 (6)
    //         004e700f     MOV        dword ptr [EAX + 0x144],this
    //                              taistrmd.cpp:120 (6)
    //         004e7015     MOV        dword ptr [EAX + 0x148],this
    //                              taistrmd.cpp:121 (6)
    //         004e701b     MOV        dword ptr [EAX + 0x14c],this
    //                              taistrmd.cpp:122 (6)
    //         004e7021     MOV        dword ptr [EAX + 0x150],this
    //                              taistrmd.cpp:123 (10)
    //         004e7027     MOV        dword ptr [EAX + 0x154],0x4
    //                              taistrmd.cpp:124 (10)
    //         004e7031     MOV        dword ptr [EAX + 0x158],0x2
    //                              taistrmd.cpp:125 (10)
    //         004e703b     MOV        dword ptr [EAX + 0x15c],0x19
    //                              taistrmd.cpp:126 (10)
    //         004e7045     MOV        dword ptr [EAX + 0x160],0x64
    //                              taistrmd.cpp:127 (6)
    //         004e704f     MOV        dword ptr [EAX + 0x164],EBP
    //                              taistrmd.cpp:128 (10)
    //         004e7055     MOV        dword ptr [EAX + 0x168],0xffffffe7
    //                              taistrmd.cpp:129 (6)
    //         004e705f     MOV        dword ptr [EAX + 0x16c],this
    //                              taistrmd.cpp:130 (10)
    //         004e7065     MOV        dword ptr [EAX + 0x170],0x64
    //                              taistrmd.cpp:131 (10)
    //         004e706f     MOV        dword ptr [EAX + 0x174],0x5
    //                              taistrmd.cpp:132 (6)
    //         004e7079     MOV        dword ptr [EAX + 0x178],EDX
    //                              taistrmd.cpp:133 (6)
    //         004e707f     MOV        dword ptr [EAX + 0x17c],this
    //                              taistrmd.cpp:134 (6)
    //         004e7085     MOV        dword ptr [EAX + 0x180],this
    //                              taistrmd.cpp:135 (6)
    //         004e708b     MOV        dword ptr [EAX + 0x184],this
    //                              taistrmd.cpp:136 (6)
    //         004e7091     MOV        dword ptr [EAX + 0x188],this
    //                              taistrmd.cpp:137 (6)
    //         004e7097     MOV        dword ptr [EAX + 0x18c],EDX
    //                              taistrmd.cpp:138 (6)
    //         004e709d     MOV        dword ptr [EAX + 0x190],EDI
    //                              taistrmd.cpp:139 (6)
    //         004e70a3     MOV        dword ptr [EAX + 0x194],EBP
    //                              taistrmd.cpp:140 (6)
    //         004e70a9     MOV        dword ptr [EAX + 0x198],EDX
    //                              taistrmd.cpp:141 (10)
    //         004e70af     MOV        dword ptr [EAX + 0x19c],0xf
    //                              taistrmd.cpp:142 (6)
    //         004e70b9     MOV        dword ptr [EAX + 0x1a0],this
    //                              taistrmd.cpp:143 (6)
    //         004e70bf     MOV        dword ptr [EAX + 0x1a4],this
    //                              taistrmd.cpp:144 (6)
    //         004e70c5     MOV        dword ptr [EAX + 0x1a8],this
    //                              taistrmd.cpp:145 (6)
    //         004e70cb     MOV        dword ptr [EAX + 0x1ac],ESI
    //                              taistrmd.cpp:146 (6)
    //         004e70d1     MOV        dword ptr [EAX + 0x1b0],ESI
    //                              taistrmd.cpp:147 (6)
    //         004e70d7     MOV        dword ptr [EAX + 0x1b4],ESI
    //                              taistrmd.cpp:148 (6)
    //         004e70dd     MOV        dword ptr [EAX + 0x1b8],this
    //                              taistrmd.cpp:149 (6)
    //         004e70e3     MOV        dword ptr [EAX + 0x1bc],this
    //                              taistrmd.cpp:150 (6)
    //         004e70e9     MOV        dword ptr [EAX + 0x1c0],this
    //                              taistrmd.cpp:151 (10)
    //         004e70ef     MOV        dword ptr [EAX + 0x1c4],0x12c
    //                              taistrmd.cpp:152 (6)
    //         004e70f9     MOV        dword ptr [EAX + 0x1c8],this
    //                              taistrmd.cpp:153 (10)
    //         004e70ff     MOV        dword ptr [EAX + 0x1cc],0x19
    //                              taistrmd.cpp:154 (6)
    //         004e7109     MOV        dword ptr [EAX + 0x1d0],EDI
    //                              taistrmd.cpp:155 (6)
    //         004e710f     MOV        dword ptr [EAX + 0x1d4],EDI
    //                              taistrmd.cpp:156 (6)
    //         004e7115     MOV        dword ptr [EAX + 0x1d8],this
    //                              taistrmd.cpp:157 (6)
    //         004e711b     MOV        dword ptr [EAX + 0x1dc],this
    //                              taistrmd.cpp:158 (6)
    //         004e7121     MOV        dword ptr [EAX + 0x1e0],this
    //                              taistrmd.cpp:159 (6)
    //         004e7127     MOV        dword ptr [EAX + 0x1e4],this
    //                              taistrmd.cpp:160 (6)
    //         004e712d     MOV        dword ptr [EAX + 0x1e8],this
    //                              taistrmd.cpp:161 (10)
    //         004e7133     MOV        dword ptr [EAX + 0x1ec],0x64
    //                              taistrmd.cpp:162 (6)
    //         004e713d     MOV        dword ptr [EAX + 0x1f0],this
    //                              taistrmd.cpp:163 (6)
    //         004e7143     MOV        dword ptr [EAX + 0x1f4],this
    //                              taistrmd.cpp:164 (6)
    //         004e7149     MOV        dword ptr [EAX + 0x1f8],this
    //                              taistrmd.cpp:165 (6)
    //         004e714f     MOV        dword ptr [EAX + 0x1fc],this
    //                              taistrmd.cpp:166 (6)
    //         004e7155     MOV        dword ptr [EAX + 0x200],this
    //                              taistrmd.cpp:167 (6)
    //         004e715b     MOV        dword ptr [EAX + 0x204],ESI
    //                              taistrmd.cpp:168 (6)
    //         004e7161     MOV        dword ptr [EAX + 0x208],this
    //                              taistrmd.cpp:169 (6)
    //         004e7167     MOV        dword ptr [EAX + 0x20c],this
    //                              taistrmd.cpp:170 (6)
    //         004e716d     MOV        dword ptr [EAX + 0x210],EBP
    //                              taistrmd.cpp:171 (6)
    //         004e7173     MOV        dword ptr [EAX + 0x214],this
    //                              taistrmd.cpp:172 (6)
    //         004e7179     MOV        dword ptr [EAX + 0x218],this
    //                              taistrmd.cpp:173 (6)
    //         004e717f     MOV        dword ptr [EAX + 0x21c],this
    //                              taistrmd.cpp:174 (6)
    //         004e7185     MOV        dword ptr [EAX + 0x220],EDX
    //                              taistrmd.cpp:175 (10)
    //         004e718b     MOV        dword ptr [EAX + 0x224],0xf
    //                              taistrmd.cpp:176 (6)
    //         004e7195     MOV        dword ptr [EAX + 0x228],this
    //                              taistrmd.cpp:177 (6)
    //         004e719b     MOV        dword ptr [EAX + 0x22c],this
    //                              taistrmd.cpp:178 (6)
    //         004e71a1     MOV        dword ptr [EAX + 0x230],this
    //                              taistrmd.cpp:179 (6)
    //         004e71a7     MOV        dword ptr [EAX + 0x234],this
    //                              taistrmd.cpp:180 (6)
    //         004e71ad     MOV        dword ptr [EAX + 0x238],this
    //                              taistrmd.cpp:181 (6)
    //         004e71b3     MOV        dword ptr [EAX + 0x23c],this
    //                              taistrmd.cpp:182 (6)
    //         004e71b9     MOV        dword ptr [EAX + 0x240],EDX
    //                              taistrmd.cpp:183 (6)
    //         004e71bf     MOV        dword ptr [EAX + 0x244],this
    //                              taistrmd.cpp:184 (6)
    //         004e71c5     MOV        dword ptr [EAX + 0x248],EDI
    //                              taistrmd.cpp:185 (6)
    //         004e71cb     MOV        dword ptr [EAX + 0x24c],EBX
    //                              taistrmd.cpp:186 (6)
    //         004e71d1     MOV        dword ptr [EAX + 0x250],EDI
    //                              taistrmd.cpp:187 (10)
    //         004e71d7     MOV        dword ptr [EAX + 0x254],0x14
    //                              taistrmd.cpp:188 (10)
    //         004e71e1     MOV        dword ptr [EAX + 0x258],0x28
    //                              taistrmd.cpp:189 (6)
    //         004e71eb     MOV        dword ptr [EAX + 0x25c],ESI
    //                              taistrmd.cpp:190 (6)
    //         004e71f1     MOV        dword ptr [EAX + 0x260],EBP
    //                              taistrmd.cpp:191 (6)
    //         004e71f7     MOV        dword ptr [EAX + 0x264],this
    //                              taistrmd.cpp:192 (6)
    //         004e71fd     MOV        dword ptr [EAX + 0x268],ESI
    //                              taistrmd.cpp:193 (6)
    //         004e7203     MOV        dword ptr [EAX + 0x26c],ESI
    //                              taistrmd.cpp:194 (6)
    //         004e7209     MOV        dword ptr [EAX + 0x270],EDI
    //                              taistrmd.cpp:195 (6)
    //         004e720f     MOV        dword ptr [EAX + 0x274],this
    //                              taistrmd.cpp:196 (6)
    //         004e7215     MOV        dword ptr [EAX + 0x278],this
    //                              taistrmd.cpp:197 (6)
    //         004e721b     MOV        dword ptr [EAX + 0x27c],this
    //                              taistrmd.cpp:198 (6)
    //         004e7221     MOV        dword ptr [EAX + 0x280],this
    //                              taistrmd.cpp:199 (6)
    //         004e7227     MOV        dword ptr [EAX + 0x284],EBX
    //                              taistrmd.cpp:200 (10)
    //         004e722d     MOV        dword ptr [EAX + 0x288],0x2
    //                              taistrmd.cpp:201 (6)
    //         004e7237     MOV        dword ptr [EAX + 0x28c],this
    //                              taistrmd.cpp:202 (10)
    //         004e723d     MOV        dword ptr [EAX + 0x290],0x7
    //                              taistrmd.cpp:203 (6)
    //         004e7247     MOV        dword ptr [EAX + 0x294],EDI
    //                              taistrmd.cpp:204 (10)
    //         004e724d     MOV        dword ptr [EAX + 0x298],0x19
    //                              taistrmd.cpp:205 (10)
    //         004e7257     MOV        dword ptr [EAX + 0x29c],0x7
    //                              taistrmd.cpp:206 (10)
    //         004e7261     MOV        dword ptr [EAX + 0x2a0],0x2
    //                              taistrmd.cpp:207 (6)
    //         004e726b     MOV        dword ptr [EAX + 0x2a4],EBX
    //                              taistrmd.cpp:208 (6)
    //         004e7271     MOV        dword ptr [EAX + 0x2a8],EDI
    //                              taistrmd.cpp:209 (10)
    //         004e7277     MOV        dword ptr [EAX + 0x2ac],0xc8
    //                              taistrmd.cpp:210 (10)
    //         004e7281     MOV        dword ptr [EAX + 0x2b0],0xfa
    //                              taistrmd.cpp:211 (10)
    //         004e728b     MOV        dword ptr [EAX + 0x2b4],0x96
    //                              taistrmd.cpp:212 (10)
    //         004e7295     MOV        dword ptr [EAX + 0x2b8],0xc8
    //                              taistrmd.cpp:213 (10)
    //         004e729f     MOV        dword ptr [EAX + 0x2bc],0x2
    //                              taistrmd.cpp:214 (6)
    //         004e72a9     MOV        dword ptr [EAX + 0x2c0],ESI
    //                              taistrmd.cpp:215 (6)
    //         004e72af     MOV        dword ptr [EAX + 0x2c4],this
    //                              taistrmd.cpp:216 (6)
    //         004e72b5     MOV        dword ptr [EAX + 0x2c8],ESI
    //                              taistrmd.cpp:217 (6)
    //         004e72bb     MOV        dword ptr [EAX + 0x2cc],EDI
    //                              taistrmd.cpp:218 (10)
    //         004e72c1     MOV        dword ptr [EAX + 0x2d0],0x1e
    //                              taistrmd.cpp:219 (6)
    //         004e72cb     MOV        dword ptr [EAX + 0x2d4],EDX
    //                              taistrmd.cpp:220 (6)
    //         004e72d1     MOV        dword ptr [EAX + 0x2d8],EDX
    //                              taistrmd.cpp:221 (6)
    //         004e72d7     MOV        dword ptr [EAX + 0x2dc],this
    //                              taistrmd.cpp:222 (6)
    //         004e72dd     MOV        dword ptr [EAX + 0x2e0],this
    //                              taistrmd.cpp:223 (10)
    //         004e72e3     MOV        dword ptr [EAX + 0x2e4],0x14
    //                              taistrmd.cpp:224 (6)
    //         004e72ed     MOV        dword ptr [EAX + 0x2e8],EBX
    //                              taistrmd.cpp:225 (6)
    //         004e72f3     MOV        dword ptr [EAX + 0x2ec],this
    //                              taistrmd.cpp:226 (6)
    //         004e72f9     MOV        dword ptr [EAX + 0x2f0],this
    //                              taistrmd.cpp:227 (6)
    //         004e72ff     MOV        dword ptr [EAX + 0x2f4],EDX
    //                              taistrmd.cpp:229 (17)
    //         004e7305     MOV        ESI,0xbb8
    //         004e730a     MOV        dword ptr [EAX + 0x2f8],EBX
    //         004e7310     MOV        dword ptr [EAX + 0x2fc],ESI
    //                              taistrmd.cpp:230 (10)
    //         004e7316     MOV        dword ptr [EAX + 0x300],0x7d0
    //                              taistrmd.cpp:231 (10)
    //         004e7320     MOV        dword ptr [EAX + 0x304],0x5dc
    //                              taistrmd.cpp:232 (6)
    //         004e732a     MOV        dword ptr [EAX + 0x308],ESI
    //                              taistrmd.cpp:234 (17)
    //         004e7330     MOV        ESI,0x19
    //         004e7335     MOV        dword ptr [EAX + 0x30c],EDX
    //         004e733b     MOV        dword ptr [EAX + 0x310],ESI
    //                              taistrmd.cpp:238 (6)
    //         004e7341     MOV        dword ptr [EAX + 0x320],ESI
    //                              taistrmd.cpp:241 (6)
    //         004e7347     MOV        dword ptr [EAX + 0x32c],ESI
    //                              taistrmd.cpp:257 (139)
    //         004e734d     MOV        ESI,0x64
    //         004e7352     MOV        dword ptr [EAX + 0x314],EDX
    //         004e7358     MOV        dword ptr [EAX + 0x318],0x78
    //         004e7362     MOV        dword ptr [EAX + 0x31c],EBX
    //         004e7368     MOV        dword ptr [EAX + 0x324],EBX
    //         004e736e     MOV        dword ptr [EAX + 0x328],this
    //         004e7374     MOV        dword ptr [EAX + 0x330],EDX
    //         004e737a     MOV        dword ptr [EAX + 0x334],0x5
    //         004e7384     MOV        dword ptr [EAX + 0x338],EDX
    //         004e738a     MOV        dword ptr [EAX + 0x33c],EDX
    //         004e7390     MOV        dword ptr [EAX + 0x340],EDX
    //         004e7396     MOV        dword ptr [EAX + 0x344],this
    //         004e739c     MOV        dword ptr [EAX + 0x348],this
    //         004e73a2     MOV        dword ptr [EAX + 0x34c],this
    //         004e73a8     MOV        dword ptr [EAX + 0x350],EDX
    //         004e73ae     MOV        dword ptr [EAX + 0x354],this
    //         004e73b4     MOV        dword ptr [EAX + 0x358],this
    //         004e73ba     MOV        dword ptr [EAX + 0x35c],this
    //         004e73c0     MOV        dword ptr [EAX + 0x360],EDX
    //         004e73c6     MOV        dword ptr [EAX + 0x364],EBX
    //         004e73cc     MOV        dword ptr [EAX + 0x368],this
    //         004e73d2     MOV        dword ptr [EAX + 0x36c],ESI
    //                              taistrmd.cpp:258 (6)
    //         004e73d8     MOV        dword ptr [EAX + 0x370],ESI
    //                              taistrmd.cpp:259 (10)
    //         004e73de     MOV        dword ptr [EAX + 0x374],0x8
    //                              taistrmd.cpp:260 (6)
    //         004e73e8     MOV        dword ptr [EAX + 0x378],EBP
    //                              taistrmd.cpp:261 (6)
    //         004e73ee     MOV        dword ptr [EAX + 0x37c],EDI
    //                              taistrmd.cpp:262 (6)
    //         004e73f4     MOV        dword ptr [EAX + 0x380],this
    //                              taistrmd.cpp:263 (6)
    //         004e73fa     MOV        dword ptr [EAX + 0x384],this
    //                              taistrmd.cpp:265 (11)
    //         004e7400     POP        EDI
    //         004e7401     POP        ESI
    //         004e7402     POP        EBP
    //         004e7403     MOV        dword ptr [EAX + 0x388],EDX
    //         004e7409     POP        EBX
    //         004e740a     RET
}

// Offset: 0x004E7430
void VictoryConditionRuleSystem(VictoryConditionRuleSystem* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall VictoryConditionRuleSystem::~VictoryConditionRuleSystem(void)              *
    //                              *********************************************************************************************************
    //                              void __thiscall ~VictoryConditionRuleSystem(VictoryConditionRuleSyst
    //              void              <VOID>         <RETURN>
    //              VictoryConditi    ECX:4 (auto)   this
    //                               ??1VictoryConditionRuleSystem@@UAE@XZ                        XREF[2]:     `scalar_deleting_destructor':004e7
    //                               VictoryConditionRuleSystem::~VictoryConditionRuleSystem                   ~TribeStrategyAIModule:004e9762(c)
    //                              taistrmd.cpp:270 (6)
    //         004e7430     MOV        dword ptr [this->_padding_],VictoryConditionRu   = 004e7410
    //                              taistrmd.cpp:271 (1)
    //         004e7436     RET
}

// Offset: 0x004E7440
int loadRules(VictoryConditionRuleSystem* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall VictoryConditionRuleSystem::loadRules(char *)                                  *
    //                              *********************************************************************************************************
    //                              int __thiscall loadRules(VictoryConditionRuleSystem * this, char * p
    //              int               EAX:4          <RETURN>
    //              VictoryConditi    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     004e7448(R)  
    //              char[256]         Stack[-0x104   temp                      XREF[2,6]:   004e7537(*), 004e7562(R), 004e74a6(*), 004e74b8(*), 
    //                                                                                     004e74d5(*), 004e74f9(*), 004e7541(*), 004e756b(*)  
    //              int               Stack[-0x108   ruleValue                 XREF[2]:     004e753b(*), 004e7550(R)  
    //              int               Stack[-0x10c   ruleIndex                 XREF[0,4]:   004e74f3(*), 004e7508(R), 004e74ef(*), 004e750c(R)  
    //              char              Stack[-0x10d   commentTemp2
    //              char              Stack[-0x10e   commentTemp1
    //                               ?loadRules@VictoryConditionRuleSystem@@QAEHPAD@Z             XREF[1]:     loadRules:004ea16c(c)  
    //                               VictoryConditionRuleSystem::loadRules
    //                              taistrmd.cpp:276 (8)
    //         004e7440     SUB        ESP,0x10c
    //         004e7446     PUSH       EBX
    //         004e7447     PUSH       EBP
    //                              taistrmd.cpp:279 (93)
    //         004e7448     MOV        EBP,dword ptr [ESP + param_1]
    //         004e744f     PUSH       ESI
    //         004e7450     PUSH       EDI
    //         004e7451     MOV        EBX,this
    //         004e7453     MOV        ESI,s_NONE                                       = 4Eh
    //         004e7458     MOV        EAX,EBP
    //                               LAB_004e745a                                                 XREF[1]:     004e7478(j)  
    //         004e745a     MOV        DL,byte ptr [EAX]
    //         004e745c     MOV        this,DL
    //         004e745e     CMP        DL,byte ptr [ESI]=>s_NONE                        = 4Eh
    //         004e7460     JNZ        LAB_004e747e
    //         004e7462     TEST       this,this
    //         004e7464     JZ         LAB_004e747a
    //         004e7466     MOV        DL,byte ptr [EAX + 0x1]
    //         004e7469     MOV        this,DL
    //         004e746b     CMP        DL,byte ptr [ESI + 0x1]=>DAT_0057f351            = 4Fh
    //                                                                                  = 45h
    //         004e746e     JNZ        LAB_004e747e
    //         004e7470     ADD        EAX,0x2
    //         004e7473     ADD        ESI,0x2
    //         004e7476     TEST       this,this
    //         004e7478     JNZ        LAB_004e745a
    //                               LAB_004e747a                                                 XREF[1]:     004e7464(j)  
    //         004e747a     XOR        EAX,EAX
    //         004e747c     JMP        LAB_004e7483
    //                               LAB_004e747e                                                 XREF[2]:     004e7460(j), 004e746e(j)  
    //         004e747e     SBB        EAX,EAX
    //         004e7480     SBB        EAX,-0x1
    //                               LAB_004e7483                                                 XREF[1]:     004e747c(j)  
    //         004e7483     TEST       EAX,EAX
    //         004e7485     JZ         LAB_004e75bb
    //         004e748b     TEST       EBP,EBP
    //         004e748d     JZ         LAB_004e75bb
    //         004e7493     MOV        EDI,EBP
    //         004e7495     OR         this,0xffffffff
    //         004e7498     XOR        EAX,EAX
    //         004e749a     SCASB.RE   ES:EDI
    //         004e749c     NOT        this
    //         004e749e     DEC        this
    //         004e749f     JZ         LAB_004e75bb
    //                              taistrmd.cpp:283 (19)
    //         004e74a5     PUSH       EBP
    //         004e74a6     LEA        EAX=>temp[4],[ESP + 0x20]
    //         004e74aa     PUSH       s_%s                                             = "%s"
    //         004e74af     PUSH       EAX
    //         004e74b0     CALL       sprintf                                          undefined sprintf()
    //         004e74b5     ADD        ESP,0xc
    //                              taistrmd.cpp:284 (20)
    //         004e74b8     LEA        this=>temp[4],[ESP + 0x1c]
    //         004e74bc     PUSH       s_r                                              = "r"
    //         004e74c1     PUSH       this
    //         004e74c2     CALL       fopen                                            undefined fopen()
    //         004e74c7     MOV        ESI,EAX
    //         004e74c9     ADD        ESP,0x8
    //                              taistrmd.cpp:285 (2)
    //         004e74cc     TEST       ESI,ESI
    //                              taistrmd.cpp:286 (6)
    //         004e74ce     JZ         LAB_004e75bb
    //                              taistrmd.cpp:289 (27)
    //         004e74d4     PUSH       ESI
    //         004e74d5     LEA        EDX=>temp[4],[ESP + 0x20]
    //         004e74d9     PUSH       0x100
    //         004e74de     PUSH       EDX
    //         004e74df     CALL       fgets                                            undefined fgets()
    //         004e74e4     ADD        ESP,0xc
    //         004e74e7     TEST       EAX,EAX
    //         004e74e9     JZ         LAB_004e7585
    //                               LAB_004e74ef                                                 XREF[1]:     004e757f(j)  
    //                              taistrmd.cpp:294 (25)
    //         004e74ef     LEA        EAX=>ruleIndex+0x3,[ESP + 0x13]
    //         004e74f3     LEA        this=>ruleIndex+0x2,[ESP + 0x12]
    //         004e74f7     PUSH       EAX
    //         004e74f8     PUSH       this
    //         004e74f9     LEA        EDX=>temp[4],[ESP + 0x24]
    //         004e74fd     PUSH       s__%c%c                                          = " %c%c"
    //         004e7502     PUSH       EDX
    //         004e7503     CALL       sscanf                                           undefined sscanf()
    //                              taistrmd.cpp:299 (36)
    //         004e7508     MOV        AL,byte ptr [ESP + ruleIndex+0x2]
    //         004e750c     MOV        this,byte ptr [ESP + ruleIndex+0x3]
    //         004e7510     ADD        ESP,0x10
    //         004e7513     CMP        AL,0x2f
    //         004e7515     JNZ        LAB_004e751c
    //         004e7517     CMP        this,0x2f
    //         004e751a     JZ         LAB_004e756a
    //                               LAB_004e751c                                                 XREF[1]:     004e7515(j)  
    //         004e751c     CMP        AL,0x44
    //         004e751e     JNZ        LAB_004e7525
    //         004e7520     CMP        this,0x45
    //         004e7523     JZ         LAB_004e756a
    //                               LAB_004e7525                                                 XREF[1]:     004e751e(j)  
    //         004e7525     CMP        AL,0x56
    //         004e7527     JNZ        LAB_004e752e
    //         004e7529     CMP        this,0x43
    //                              taistrmd.cpp:300 (2)
    //         004e752c     JZ         LAB_004e756a
    //                               LAB_004e752e                                                 XREF[1]:     004e7527(j)  
    //                              taistrmd.cpp:302 (9)
    //         004e752e     CMP        AL,0x45
    //         004e7530     JNZ        LAB_004e7537
    //         004e7532     CMP        this,0x4e
    //         004e7535     JZ         LAB_004e7585
    //                               LAB_004e7537                                                 XREF[1]:     004e7530(j)  
    //                              taistrmd.cpp:305 (25)
    //         004e7537     LEA        EAX=>temp,[ESP + 0x18]
    //         004e753b     LEA        this=>ruleValue,[ESP + 0x14]
    //         004e753f     PUSH       EAX
    //         004e7540     PUSH       this
    //         004e7541     LEA        EDX=>temp[4],[ESP + 0x24]
    //         004e7545     PUSH       s_%d_%d_                                         = "%d %d "
    //         004e754a     PUSH       EDX
    //         004e754b     CALL       sscanf                                           undefined sscanf()
    //                              taistrmd.cpp:307 (18)
    //         004e7550     MOV        EAX,dword ptr [ESP + ruleValue]
    //         004e7554     ADD        ESP,0x10
    //         004e7557     TEST       EAX,EAX
    //         004e7559     JL         LAB_004e756a
    //         004e755b     CMP        EAX,0xe2
    //         004e7560     JGE        LAB_004e756a
    //                              taistrmd.cpp:308 (35)
    //         004e7562     MOV        this,dword ptr [ESP + temp[0]]
    //         004e7566     MOV        dword ptr [EBX + EAX*0x4 + 0x4],this
    //                               LAB_004e756a                                                 XREF[5]:     004e751a(j), 004e7523(j), 
    //                                                                                                         004e752c(j), 004e7559(j), 
    //                                                                                                         004e7560(j)  
    //         004e756a     PUSH       ESI
    //         004e756b     LEA        EDX=>temp[4],[ESP + 0x20]
    //         004e756f     PUSH       0x100
    //         004e7574     PUSH       EDX
    //         004e7575     CALL       fgets                                            undefined fgets()
    //         004e757a     ADD        ESP,0xc
    //         004e757d     TEST       EAX,EAX
    //         004e757f     JNZ        LAB_004e74ef
    //                               LAB_004e7585                                                 XREF[2]:     004e74e9(j), 004e7535(j)  
    //                              taistrmd.cpp:312 (9)
    //         004e7585     PUSH       ESI
    //         004e7586     CALL       fclose                                           undefined fclose()
    //         004e758b     ADD        ESP,0x4
    //                              taistrmd.cpp:314 (18)
    //         004e758e     PUSH       s_.tmp                                           = ".tmp"
    //         004e7593     PUSH       EBP
    //         004e7594     CALL       strstr                                           undefined strstr()
    //         004e7599     ADD        ESP,0x8
    //         004e759c     TEST       EAX,EAX
    //         004e759e     JZ         LAB_004e75a9
    //                              taistrmd.cpp:315 (9)
    //         004e75a0     PUSH       EBP
    //         004e75a1     CALL       __unlink                                         undefined __unlink()
    //         004e75a6     ADD        ESP,0x4
    //                               LAB_004e75a9                                                 XREF[1]:     004e759e(j)  
    //                              taistrmd.cpp:316 (5)
    //         004e75a9     MOV        EAX,0x1
    //                              taistrmd.cpp:317 (28)
    //         004e75ae     POP        EDI
    //         004e75af     POP        ESI
    //         004e75b0     POP        EBP
    //         004e75b1     POP        EBX
    //         004e75b2     ADD        ESP,0x10c
    //         004e75b8     RET        0x4
    //                               LAB_004e75bb                                                 XREF[4]:     004e7485(j), 004e748d(j), 
    //                                                                                                         004e749f(j), 004e74ce(j)  
    //         004e75bb     POP        EDI
    //         004e75bc     POP        ESI
    //         004e75bd     POP        EBP
    //         004e75be     XOR        EAX,EAX
    //         004e75c0     POP        EBX
    //         004e75c1     ADD        ESP,0x10c
    //         004e75c7     RET        0x4
}

// Offset: 0x004E75D0
void setRule(VictoryConditionRuleSystem* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall VictoryConditionRuleSystem::setRule(int,int)                                  *
    //                              *********************************************************************************************************
    //                              void __thiscall setRule(VictoryConditionRuleSystem * this, int param
    //              void              <VOID>         <RETURN>
    //              VictoryConditi    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004e75d0(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004e75df(R)  
    //                               ?setRule@VictoryConditionRuleSystem@@QAEXHH@Z                XREF[1]:     setRule:004ea1a5(c)  
    //                               VictoryConditionRuleSystem::setRule
    //                              taistrmd.cpp:322 (15)
    //         004e75d0     MOV        EAX,dword ptr [ESP + param_1]
    //         004e75d4     TEST       EAX,EAX
    //         004e75d6     JL         LAB_004e75e7
    //         004e75d8     CMP        EAX,0xe2
    //         004e75dd     JGE        LAB_004e75e7
    //                              taistrmd.cpp:324 (8)
    //         004e75df     MOV        EDX,dword ptr [ESP + param_2]
    //         004e75e3     MOV        dword ptr [ECX + EAX*this->sn[0] + 0x4],EDX
    //                               LAB_004e75e7                                                 XREF[2]:     004e75d6(j), 004e75dd(j)  
    //                              taistrmd.cpp:325 (3)
    //         004e75e7     RET        0x8
}

// Offset: 0x004E75F0
int rule(VictoryConditionRuleSystem* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall VictoryConditionRuleSystem::rule(int)                                          *
    //                              *********************************************************************************************************
    //                              int __thiscall rule(VictoryConditionRuleSystem * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              VictoryConditi    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004e75f0(R)  
    //                               ?rule@VictoryConditionRuleSystem@@QAEHH@Z                    XREF[1]:     rule:004ea1bb(c)  
    //                               VictoryConditionRuleSystem::rule
    //                              taistrmd.cpp:330 (15)
    //         004e75f0     MOV        EAX,dword ptr [ESP + param_1]
    //         004e75f4     TEST       EAX,EAX
    //         004e75f6     JL         LAB_004e7606
    //         004e75f8     CMP        EAX,0xe2
    //         004e75fd     JGE        LAB_004e7606
    //                              taistrmd.cpp:332 (4)
    //         004e75ff     MOV        EAX,dword ptr [ECX + EAX*this->sn[0] + 0x4]
    //                              taistrmd.cpp:334 (3)
    //         004e7603     RET        0x4
    //                               LAB_004e7606                                                 XREF[2]:     004e75f6(j), 004e75fd(j)  
    //                              taistrmd.cpp:333 (3)
    //         004e7606     OR         EAX,0xffffffff
    //                              taistrmd.cpp:334 (3)
    //         004e7609     RET        0x4
}

// Offset: 0x004E7610
int evaluateAsInProgress(VictoryConditionRuleSystem* this_, TRIBE_Player* param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall VictoryConditionRuleSystem::evaluateAsInProgress(class TRIBE_Player *,int)     *
    //                              *********************************************************************************************************
    //                              int __thiscall evaluateAsInProgress(VictoryConditionRuleSystem * thi
    //              int               EAX:4          <RETURN>
    //              VictoryConditi    ECX:4 (auto)   this
    //              TRIBE_Player *    Stack[0x4]:4   param_1
    //              int               Stack[0x8]:4   param_2
    //                               ?evaluateAsInProgress@VictoryConditionRuleSystem@@QAEHPAVTR  XREF[1]:     update:004e9b31(c)  
    //                               VictoryConditionRuleSystem::evaluateAsInProgress
    //                              taistrmd.cpp:340 (2)
    //         004e7610     XOR        EAX,EAX
    //                              taistrmd.cpp:347 (3)
    //         004e7612     RET        0x8
}

// Offset: 0x004E7620
int evaluateAsNonInProgress(VictoryConditionRuleSystem* this_, TRIBE_Player* param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall VictoryConditionRuleSystem::evaluateAsNonInProgress(class TRIBE_Player *,int)  *
    //                              *********************************************************************************************************
    //                              int __thiscall evaluateAsNonInProgress(VictoryConditionRuleSystem * 
    //              int               EAX:4          <RETURN>
    //              VictoryConditi    ECX:4 (auto)   this
    //              TRIBE_Player *    Stack[0x4]:4   param_1
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004e7620(R)  
    //                               ?evaluateAsNonInProgress@VictoryConditionRuleSystem@@QAEHPA  XREF[3]:     update:004e994f(c), 
    //                               VictoryConditionRuleSystem::evaluateAsNonInProgress                       update:004e9cd2(c), 
    //                                                                                                         setVictoryCondition:004ea6e2(c)  
    //                              taistrmd.cpp:353 (25)
    //         004e7620     MOV        EAX,dword ptr [ESP + param_2]
    //         004e7624     DEC        EAX
    //         004e7625     CMP        EAX,0x30
    //         004e7628     JA         switchD_004e7632::caseD_3
    //         004e762a     XOR        this,this
    //         004e762c     MOV        this,byte ptr [EAX + 0x4e765c]=>PTR_caseD_3_00
    //                               switchD_004e7632::switchD
    //         004e7632     JMP        dword ptr [this->_padding_*0x4 + switchD_004e7   = 004e7639
    //                               switchD_004e7632::caseD_2                                    XREF[5]:     004e7632(j), 004e7648(*), 
    //                               switchD_004e7632::caseD_c                                                 004e764c(*), 004e7650(*), 
    //                               switchD_004e7632::caseD_d                                                 004e7654(*)  
    //                               switchD_004e7632::caseD_e
    //                               switchD_004e7632::caseD_10
    //                               switchD_004e7632::caseD_11
    //                               switchD_004e7632::caseD_12
    //                               switchD_004e7632::caseD_15
    //                               switchD_004e7632::caseD_16
    //                               switchD_004e7632::caseD_17
    //                               switchD_004e7632::caseD_18
    //                               switchD_004e7632::caseD_19
    //                               switchD_004e7632::caseD_1a
    //                               switchD_004e7632::caseD_1b
    //                               switchD_004e7632::caseD_1c
    //                               switchD_004e7632::caseD_1d
    //                               switchD_004e7632::caseD_1e
    //                               switchD_004e7632::caseD_1f
    //                               switchD_004e7632::caseD_20
    //                               switchD_004e7632::caseD_21
    //                               switchD_004e7632::caseD_22
    //                               switchD_004e7632::caseD_23
    //                               switchD_004e7632::caseD_24
    //                               switchD_004e7632::caseD_25
    //                               switchD_004e7632::caseD_26
    //                               switchD_004e7632::caseD_27
    //                               switchD_004e7632::caseD_28
    //                               switchD_004e7632::caseD_29
    //                               switchD_004e7632::caseD_2a
    //                               switchD_004e7632::caseD_2b
    //                               switchD_004e7632::caseD_2c
    //                               switchD_004e7632::caseD_2d
    //                               switchD_004e7632::caseD_2e
    //                               switchD_004e7632::caseD_2f
    //                               switchD_004e7632::caseD_30
    //                               switchD_004e7632::caseD_31
    //                               switchD_004e7632::caseD_1
    //                              taistrmd.cpp:400 (5)
    //         004e7639     MOV        EAX,DAT_fffffffe
    //                              taistrmd.cpp:404 (3)
    //         004e763e     RET        0x8
    //                               switchD_004e7632::caseD_4                                    XREF[3]:     004e7628(j), 004e7632(j), 
    //                               switchD_004e7632::caseD_5                                                 004e7658(*)  
    //                               switchD_004e7632::caseD_6
    //                               switchD_004e7632::caseD_7
    //                               switchD_004e7632::caseD_8
    //                               switchD_004e7632::caseD_9
    //                               switchD_004e7632::caseD_a
    //                               switchD_004e7632::caseD_b
    //                               switchD_004e7632::caseD_f
    //                               switchD_004e7632::caseD_13
    //                               switchD_004e7632::caseD_14
    //                               switchD_004e7632::caseD_3
    //                              taistrmd.cpp:403 (2)
    //         004e7641     XOR        EAX,EAX
    //                              taistrmd.cpp:404 (74)
    //         004e7643     RET        0x8
}

// Offset: 0x004E7646
undefined FUN_004e7646() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_004e7646()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_004e7646
    //         004e7646     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004e7632::switchdataD_004e7648                       XREF[1]:     evaluateAsNonInProgress:004e7632(*
}

// Offset: 0x004E7690
int execute(VictoryConditionRuleSystem* this_, TRIBE_Player* param_2, int param_3, int param_4) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall VictoryConditionRuleSystem::execute(class TRIBE_Player *,int,int)              *
    //                              *********************************************************************************************************
    //                              int __thiscall execute(VictoryConditionRuleSystem * this, TRIBE_Play
    //              int               EAX:4          <RETURN>
    //              VictoryConditi    ECX:4 (auto)   this
    //              TRIBE_Player *    Stack[0x4]:4   param_1                   XREF[37]:    004e76be(R), 004e7c9e(R), 004e7dba(R), 004e7dcf(R), 
    //                                                                                     004e7de4(R), 004e7df6(R), 004e7e56(R), 004e7e6b(R), 
    //                                                                                     004e7e7d(R), 004e7eda(R), 004e7eec(R), 004e7f21(R), 
    //                                                                                     004e7f33(R), 004e7f65(R), 004e7f77(R), 004e7fd7(R), 
    //                                                                                     004e8068(R), 004e8105(R), 004e8117(R), 004e8180(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004e7690(R)  
    //              int               Stack[0xc]:4   param_3                   XREF[1]:     004e76a9(R)  
    //                               ?execute@VictoryConditionRuleSystem@@QAEHPAVTRIBE_Player@@H  XREF[3]:     update:004e99f3(c), 
    //                               VictoryConditionRuleSystem::execute                                       update:004e9d6c(c), 
    //                                                                                                         setVictoryCondition:004ea70d(c)  
    //                              taistrmd.cpp:410 (25)
    //         004e7690     MOV        EAX,dword ptr [ESP + param_2]
    //         004e7694     PUSH       ESI
    //         004e7695     TEST       EAX,EAX
    //         004e7697     PUSH       EDI
    //         004e7698     MOV        ESI,this
    //         004e769a     JL         switchD_004e76b7::caseD_3
    //         004e76a0     CMP        EAX,0xd
    //         004e76a3     JGE        switchD_004e76b7::caseD_3
    //                              taistrmd.cpp:417 (21)
    //         004e76a9     MOV        EAX,dword ptr [ESP + param_3]
    //         004e76ad     DEC        EAX
    //         004e76ae     CMP        EAX,0x30
    //         004e76b1     JA         switchD_004e76b7::caseD_3
    //                               switchD_004e76b7::switchD
    //         004e76b7     JMP        dword ptr [EAX*0x4 + switchD_004e76b7::switchd   = 004e76be
    //                               switchD_004e76b7::caseD_1                                    XREF[2]:     004e76b7(j), 004e8c44(*)  
    //                              taistrmd.cpp:422 (27)
    //         004e76be     MOV        EDI,dword ptr [ESP + param_1]
    //         004e76c2     MOV        this,dword ptr [ESI + 0x4]
    //         004e76c5     PUSH       this
    //         004e76c6     PUSH       0x0
    //         004e76c8     MOV        this,dword ptr [EDI + 0x238]
    //         004e76ce     ADD        this,0x1146c
    //         004e76d4     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:424 (23)
    //         004e76d9     MOV        EDX,dword ptr [ESI + 0x8]
    //         004e76dc     MOV        this,dword ptr [EDI + 0x238]
    //         004e76e2     PUSH       EDX
    //         004e76e3     PUSH       0x1
    //         004e76e5     ADD        this,0x1146c
    //         004e76eb     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:426 (23)
    //         004e76f0     MOV        EAX,dword ptr [ESI + 0xc]
    //         004e76f3     MOV        this,dword ptr [EDI + 0x238]
    //         004e76f9     PUSH       EAX
    //         004e76fa     PUSH       0x2
    //         004e76fc     ADD        this,0x1146c
    //         004e7702     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:428 (23)
    //         004e7707     MOV        this,dword ptr [ESI + 0x10]
    //         004e770a     PUSH       this
    //         004e770b     MOV        this,dword ptr [EDI + 0x238]
    //         004e7711     PUSH       0x3
    //         004e7713     ADD        this,0x1146c
    //         004e7719     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:430 (23)
    //         004e771e     MOV        EDX,dword ptr [ESI + 0x14]
    //         004e7721     MOV        this,dword ptr [EDI + 0x238]
    //         004e7727     PUSH       EDX
    //         004e7728     PUSH       0x4
    //         004e772a     ADD        this,0x1146c
    //         004e7730     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:432 (23)
    //         004e7735     MOV        EAX,dword ptr [ESI + 0x18]
    //         004e7738     MOV        this,dword ptr [EDI + 0x238]
    //         004e773e     PUSH       EAX
    //         004e773f     PUSH       0x5
    //         004e7741     ADD        this,0x1146c
    //         004e7747     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:434 (26)
    //         004e774c     MOV        this,dword ptr [ESI + 0x90]
    //         004e7752     PUSH       this
    //         004e7753     MOV        this,dword ptr [EDI + 0x238]
    //         004e7759     PUSH       0x23
    //         004e775b     ADD        this,0x1146c
    //         004e7761     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:436 (26)
    //         004e7766     MOV        EDX,dword ptr [ESI + 0x194]
    //         004e776c     MOV        this,dword ptr [EDI + 0x238]
    //         004e7772     PUSH       EDX
    //         004e7773     PUSH       0x64
    //         004e7775     ADD        this,0x1146c
    //         004e777b     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:439 (29)
    //         004e7780     MOV        EAX,dword ptr [ESI + 0x388]
    //         004e7786     MOV        this,dword ptr [EDI + 0x238]
    //         004e778c     PUSH       EAX
    //         004e778d     PUSH       0xe1
    //         004e7792     ADD        this,0x1146c
    //         004e7798     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:442 (26)
    //         004e779d     MOV        this,dword ptr [ESI + 0x1d8]
    //         004e77a3     PUSH       this
    //         004e77a4     MOV        this,dword ptr [EDI + 0x238]
    //                              language.dll match for 0x75: "12"
    //         004e77aa     PUSH       0x75
    //         004e77ac     ADD        this,0x1146c
    //         004e77b2     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:444 (26)
    //         004e77b7     MOV        EDX,dword ptr [ESI + 0x1dc]
    //         004e77bd     MOV        this,dword ptr [EDI + 0x238]
    //         004e77c3     PUSH       EDX
    //                              language.dll match for 0x76: "B"
    //         004e77c4     PUSH       0x76
    //         004e77c6     ADD        this,0x1146c
    //         004e77cc     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:446 (26)
    //         004e77d1     MOV        EAX,dword ptr [ESI + 0x1e0]
    //         004e77d7     MOV        this,dword ptr [EDI + 0x238]
    //         004e77dd     PUSH       EAX
    //                              language.dll match for 0x77: "Arial"
    //         004e77de     PUSH       0x77
    //         004e77e0     ADD        this,0x1146c
    //         004e77e6     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:448 (26)
    //         004e77eb     MOV        this,dword ptr [ESI + 0x1e4]
    //         004e77f1     PUSH       this
    //         004e77f2     MOV        this,dword ptr [EDI + 0x238]
    //                              language.dll match for 0x78: "10"
    //         004e77f8     PUSH       0x78
    //         004e77fa     ADD        this,0x1146c
    //         004e7800     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:451 (29)
    //         004e7805     MOV        EDX,dword ptr [ESI + 0x274]
    //         004e780b     PUSH       EDX
    //         004e780c     MOV        this,dword ptr [EDI + 0x238]
    //         004e7812     PUSH       0x9c
    //         004e7817     ADD        this,0x1146c
    //         004e781d     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:453 (29)
    //         004e7822     MOV        EAX,dword ptr [ESI + 0x280]
    //         004e7828     MOV        this,dword ptr [EDI + 0x238]
    //         004e782e     PUSH       EAX
    //         004e782f     PUSH       0x9f
    //         004e7834     ADD        this,0x1146c
    //         004e783a     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:455 (29)
    //         004e783f     MOV        this,dword ptr [ESI + 0x27c]
    //         004e7845     PUSH       this
    //         004e7846     MOV        this,dword ptr [EDI + 0x238]
    //         004e784c     PUSH       0x9e
    //         004e7851     ADD        this,0x1146c
    //         004e7857     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:457 (29)
    //         004e785c     MOV        EDX,dword ptr [ESI + 0x278]
    //         004e7862     MOV        this,dword ptr [EDI + 0x238]
    //         004e7868     PUSH       EDX
    //         004e7869     PUSH       0x9d
    //         004e786e     ADD        this,0x1146c
    //         004e7874     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:459 (29)
    //         004e7879     MOV        EAX,dword ptr [ESI + 0x284]
    //         004e787f     MOV        this,dword ptr [EDI + 0x238]
    //         004e7885     PUSH       EAX
    //         004e7886     PUSH       0xa0
    //         004e788b     ADD        this,0x1146c
    //         004e7891     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:462 (29)
    //         004e7896     MOV        this,dword ptr [ESI + 0x23c]
    //         004e789c     PUSH       this
    //         004e789d     MOV        this,dword ptr [EDI + 0x238]
    //         004e78a3     PUSH       0x8e
    //         004e78a8     ADD        this,0x1146c
    //         004e78ae     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:464 (29)
    //         004e78b3     MOV        EDX,dword ptr [ESI + 0x254]
    //         004e78b9     MOV        this,dword ptr [EDI + 0x238]
    //         004e78bf     PUSH       EDX
    //         004e78c0     PUSH       0x94
    //         004e78c5     ADD        this,0x1146c
    //         004e78cb     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:466 (29)
    //         004e78d0     MOV        EAX,dword ptr [ESI + 0x258]
    //         004e78d6     MOV        this,dword ptr [EDI + 0x238]
    //         004e78dc     PUSH       EAX
    //         004e78dd     PUSH       0x95
    //         004e78e2     ADD        this,0x1146c
    //         004e78e8     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:468 (29)
    //         004e78ed     MOV        this,dword ptr [ESI + 0x330]
    //         004e78f3     PUSH       this
    //         004e78f4     MOV        this,dword ptr [EDI + 0x238]
    //         004e78fa     PUSH       0xcb
    //         004e78ff     ADD        this,0x1146c
    //         004e7905     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:471 (29)
    //         004e790a     MOV        EDX,dword ptr [ESI + 0x290]
    //         004e7910     MOV        this,dword ptr [EDI + 0x238]
    //         004e7916     PUSH       EDX
    //         004e7917     PUSH       0xa3
    //         004e791c     ADD        this,0x1146c
    //         004e7922     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:473 (29)
    //         004e7927     MOV        EAX,dword ptr [ESI + 0x294]
    //         004e792d     MOV        this,dword ptr [EDI + 0x238]
    //         004e7933     PUSH       EAX
    //         004e7934     PUSH       0xa4
    //         004e7939     ADD        this,0x1146c
    //         004e793f     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:475 (29)
    //         004e7944     MOV        this,dword ptr [ESI + 0x29c]
    //         004e794a     PUSH       this
    //         004e794b     MOV        this,dword ptr [EDI + 0x238]
    //         004e7951     PUSH       0xa6
    //         004e7956     ADD        this,0x1146c
    //         004e795c     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:477 (29)
    //         004e7961     MOV        EDX,dword ptr [ESI + 0x298]
    //         004e7967     MOV        this,dword ptr [EDI + 0x238]
    //         004e796d     PUSH       EDX
    //         004e796e     PUSH       0xa5
    //         004e7973     ADD        this,0x1146c
    //         004e7979     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:480 (29)
    //         004e797e     MOV        EAX,dword ptr [ESI + 0x2a0]
    //         004e7984     MOV        this,dword ptr [EDI + 0x238]
    //         004e798a     PUSH       EAX
    //         004e798b     PUSH       0xa7
    //         004e7990     ADD        this,0x1146c
    //         004e7996     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:482 (29)
    //         004e799b     MOV        this,dword ptr [ESI + 0x2d0]
    //         004e79a1     PUSH       this
    //         004e79a2     MOV        this,dword ptr [EDI + 0x238]
    //         004e79a8     PUSH       0xb3
    //         004e79ad     ADD        this,0x1146c
    //         004e79b3     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:485 (29)
    //         004e79b8     MOV        EDX,dword ptr [ESI + 0x2d4]
    //         004e79be     MOV        this,dword ptr [EDI + 0x238]
    //         004e79c4     PUSH       EDX
    //         004e79c5     PUSH       0xb4
    //         004e79ca     ADD        this,0x1146c
    //         004e79d0     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:487 (29)
    //         004e79d5     MOV        EAX,dword ptr [ESI + 0x338]
    //         004e79db     MOV        this,dword ptr [EDI + 0x238]
    //         004e79e1     PUSH       EAX
    //         004e79e2     PUSH       0xcd
    //         004e79e7     ADD        this,0x1146c
    //         004e79ed     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:489 (29)
    //         004e79f2     MOV        this,dword ptr [ESI + 0x340]
    //         004e79f8     PUSH       this
    //         004e79f9     MOV        this,dword ptr [EDI + 0x238]
    //         004e79ff     PUSH       0xcf
    //         004e7a04     ADD        this,0x1146c
    //         004e7a0a     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:491 (29)
    //         004e7a0f     MOV        EDX,dword ptr [ESI + 0x33c]
    //         004e7a15     MOV        this,dword ptr [EDI + 0x238]
    //         004e7a1b     PUSH       EDX
    //         004e7a1c     PUSH       0xce
    //         004e7a21     ADD        this,0x1146c
    //         004e7a27     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:493 (29)
    //         004e7a2c     MOV        EAX,dword ptr [ESI + 0x374]
    //         004e7a32     MOV        this,dword ptr [EDI + 0x238]
    //         004e7a38     PUSH       EAX
    //         004e7a39     PUSH       0xdc
    //         004e7a3e     ADD        this,0x1146c
    //         004e7a44     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:495 (29)
    //         004e7a49     MOV        this,dword ptr [ESI + 0x37c]
    //         004e7a4f     PUSH       this
    //         004e7a50     MOV        this,dword ptr [EDI + 0x238]
    //         004e7a56     PUSH       0xde
    //         004e7a5b     ADD        this,0x1146c
    //         004e7a61     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:497 (29)
    //         004e7a66     MOV        EDX,dword ptr [ESI + 0x344]
    //         004e7a6c     MOV        this,dword ptr [EDI + 0x238]
    //         004e7a72     PUSH       EDX
    //         004e7a73     PUSH       0xd0
    //         004e7a78     ADD        this,0x1146c
    //         004e7a7e     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:499 (29)
    //         004e7a83     MOV        EAX,dword ptr [ESI + 0x348]
    //         004e7a89     MOV        this,dword ptr [EDI + 0x238]
    //         004e7a8f     PUSH       EAX
    //         004e7a90     PUSH       0xd1
    //         004e7a95     ADD        this,0x1146c
    //         004e7a9b     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:501 (29)
    //         004e7aa0     MOV        this,dword ptr [ESI + 0x34c]
    //         004e7aa6     PUSH       this
    //         004e7aa7     MOV        this,dword ptr [EDI + 0x238]
    //         004e7aad     PUSH       0xd2
    //         004e7ab2     ADD        this,0x1146c
    //         004e7ab8     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:503 (29)
    //         004e7abd     MOV        EDX,dword ptr [ESI + 0x350]
    //         004e7ac3     MOV        this,dword ptr [EDI + 0x238]
    //         004e7ac9     PUSH       EDX
    //         004e7aca     PUSH       0xd3
    //         004e7acf     ADD        this,0x1146c
    //         004e7ad5     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:505 (29)
    //         004e7ada     MOV        EAX,dword ptr [ESI + 0x380]
    //         004e7ae0     MOV        this,dword ptr [EDI + 0x238]
    //         004e7ae6     PUSH       EAX
    //         004e7ae7     PUSH       0xdf
    //         004e7aec     ADD        this,0x1146c
    //         004e7af2     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:508 (29)
    //         004e7af7     MOV        this,dword ptr [ESI + 0x354]
    //         004e7afd     PUSH       this
    //         004e7afe     MOV        this,dword ptr [EDI + 0x238]
    //         004e7b04     PUSH       0xd4
    //         004e7b09     ADD        this,0x1146c
    //         004e7b0f     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:510 (29)
    //         004e7b14     MOV        EDX,dword ptr [ESI + 0x358]
    //         004e7b1a     PUSH       EDX
    //         004e7b1b     MOV        this,dword ptr [EDI + 0x238]
    //         004e7b21     PUSH       0xd5
    //         004e7b26     ADD        this,0x1146c
    //         004e7b2c     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:512 (29)
    //         004e7b31     MOV        EAX,dword ptr [ESI + 0x35c]
    //         004e7b37     MOV        this,dword ptr [EDI + 0x238]
    //         004e7b3d     PUSH       EAX
    //         004e7b3e     PUSH       0xd6
    //         004e7b43     ADD        this,0x1146c
    //         004e7b49     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:514 (29)
    //         004e7b4e     MOV        this,dword ptr [ESI + 0x384]
    //         004e7b54     PUSH       this
    //         004e7b55     MOV        this,dword ptr [EDI + 0x238]
    //         004e7b5b     PUSH       0xe0
    //         004e7b60     ADD        this,0x1146c
    //         004e7b66     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:517 (29)
    //         004e7b6b     MOV        EDX,dword ptr [ESI + 0x2a8]
    //         004e7b71     MOV        this,dword ptr [EDI + 0x238]
    //         004e7b77     PUSH       EDX
    //         004e7b78     PUSH       0xa9
    //         004e7b7d     ADD        this,0x1146c
    //         004e7b83     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:519 (29)
    //         004e7b88     MOV        EAX,dword ptr [ESI + 0x2ac]
    //         004e7b8e     MOV        this,dword ptr [EDI + 0x238]
    //         004e7b94     PUSH       EAX
    //         004e7b95     PUSH       0xaa
    //         004e7b9a     ADD        this,0x1146c
    //         004e7ba0     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:521 (29)
    //         004e7ba5     MOV        this,dword ptr [ESI + 0x2b0]
    //         004e7bab     PUSH       this
    //         004e7bac     MOV        this,dword ptr [EDI + 0x238]
    //         004e7bb2     PUSH       0xab
    //         004e7bb7     ADD        this,0x1146c
    //         004e7bbd     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:523 (29)
    //         004e7bc2     MOV        EDX,dword ptr [ESI + 0x2b4]
    //         004e7bc8     MOV        this,dword ptr [EDI + 0x238]
    //         004e7bce     PUSH       EDX
    //         004e7bcf     PUSH       0xac
    //         004e7bd4     ADD        this,0x1146c
    //         004e7bda     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:525 (29)
    //         004e7bdf     MOV        EAX,dword ptr [ESI + 0x2b8]
    //         004e7be5     MOV        this,dword ptr [EDI + 0x238]
    //         004e7beb     PUSH       EAX
    //         004e7bec     PUSH       0xad
    //         004e7bf1     ADD        this,0x1146c
    //         004e7bf7     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:528 (29)
    //         004e7bfc     MOV        this,dword ptr [ESI + 0x2fc]
    //         004e7c02     PUSH       this
    //         004e7c03     MOV        this,dword ptr [EDI + 0x238]
    //         004e7c09     PUSH       0xbe
    //         004e7c0e     ADD        this,0x1146c
    //         004e7c14     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:530 (29)
    //         004e7c19     MOV        EDX,dword ptr [ESI + 0x300]
    //         004e7c1f     MOV        this,dword ptr [EDI + 0x238]
    //         004e7c25     PUSH       EDX
    //         004e7c26     PUSH       0xbf
    //         004e7c2b     ADD        this,0x1146c
    //         004e7c31     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:532 (29)
    //         004e7c36     MOV        EAX,dword ptr [ESI + 0x304]
    //         004e7c3c     MOV        this,dword ptr [EDI + 0x238]
    //         004e7c42     PUSH       EAX
    //         004e7c43     PUSH       0xc0
    //         004e7c48     ADD        this,0x1146c
    //         004e7c4e     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:534 (29)
    //         004e7c53     MOV        this,dword ptr [ESI + 0x308]
    //         004e7c59     PUSH       this
    //         004e7c5a     MOV        this,dword ptr [EDI + 0x238]
    //         004e7c60     PUSH       0xc1
    //         004e7c65     ADD        this,0x1146c
    //         004e7c6b     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:537 (29)
    //         004e7c70     MOV        EDX,dword ptr [ESI + 0x2bc]
    //         004e7c76     MOV        this,dword ptr [EDI + 0x238]
    //         004e7c7c     PUSH       EDX
    //         004e7c7d     PUSH       0xae
    //         004e7c82     ADD        this,0x1146c
    //         004e7c88     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:540 (12)
    //         004e7c8d     MOV        EAX,dword ptr [ESI + 0x334]
    //         004e7c93     PUSH       EAX
    //         004e7c94     PUSH       0xcc
    //                              taistrmd.cpp:541 (5)
    //         004e7c99     JMP        LAB_004e8c20
    //                               switchD_004e76b7::caseD_2                                    XREF[2]:     004e76b7(j), 004e8c48(*)  
    //                              taistrmd.cpp:545 (27)
    //         004e7c9e     MOV        EDI,dword ptr [ESP + param_1]
    //         004e7ca2     MOV        this,dword ptr [ESI + 0x44]
    //         004e7ca5     PUSH       this
    //         004e7ca6     PUSH       0x10
    //         004e7ca8     MOV        this,dword ptr [EDI + 0x238]
    //         004e7cae     ADD        this,0x1146c
    //         004e7cb4     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:547 (23)
    //         004e7cb9     MOV        EDX,dword ptr [ESI + 0x6c]
    //         004e7cbc     MOV        this,dword ptr [EDI + 0x238]
    //         004e7cc2     PUSH       EDX
    //         004e7cc3     PUSH       0x1a
    //         004e7cc5     ADD        this,0x1146c
    //         004e7ccb     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:549 (26)
    //         004e7cd0     MOV        EAX,dword ptr [ESI + 0x94]
    //         004e7cd6     MOV        this,dword ptr [EDI + 0x238]
    //         004e7cdc     PUSH       EAX
    //         004e7cdd     PUSH       0x24
    //         004e7cdf     ADD        this,0x1146c
    //         004e7ce5     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:551 (26)
    //         004e7cea     MOV        this,dword ptr [ESI + 0x98]
    //         004e7cf0     PUSH       this
    //         004e7cf1     MOV        this,dword ptr [EDI + 0x238]
    //         004e7cf7     PUSH       0x25
    //         004e7cf9     ADD        this,0x1146c
    //         004e7cff     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:553 (26)
    //         004e7d04     MOV        EDX,dword ptr [ESI + 0x178]
    //         004e7d0a     MOV        this,dword ptr [EDI + 0x238]
    //         004e7d10     PUSH       EDX
    //         004e7d11     PUSH       0x5d
    //         004e7d13     ADD        this,0x1146c
    //         004e7d19     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:555 (26)
    //         004e7d1e     MOV        EAX,dword ptr [ESI + 0x17c]
    //         004e7d24     MOV        this,dword ptr [EDI + 0x238]
    //         004e7d2a     PUSH       EAX
    //         004e7d2b     PUSH       0x5e
    //         004e7d2d     ADD        this,0x1146c
    //         004e7d33     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:557 (26)
    //         004e7d38     MOV        this,dword ptr [ESI + 0x18c]
    //         004e7d3e     PUSH       this
    //         004e7d3f     MOV        this,dword ptr [EDI + 0x238]
    //         004e7d45     PUSH       0x62
    //         004e7d47     ADD        this,0x1146c
    //         004e7d4d     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:559 (26)
    //         004e7d52     MOV        EDX,dword ptr [ESI + 0x1e8]
    //         004e7d58     MOV        this,dword ptr [EDI + 0x238]
    //         004e7d5e     PUSH       EDX
    //                              language.dll match for 0x79: "N"
    //         004e7d5f     PUSH       0x79
    //         004e7d61     ADD        this,0x1146c
    //         004e7d67     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:561 (29)
    //         004e7d6c     MOV        EAX,dword ptr [ESI + 0x210]
    //         004e7d72     MOV        this,dword ptr [EDI + 0x238]
    //         004e7d78     PUSH       EAX
    //                              language.dll match for 0x83: "Arial"
    //         004e7d79     PUSH       0x83
    //         004e7d7e     ADD        this,0x1146c
    //         004e7d84     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:563 (29)
    //         004e7d89     MOV        this,dword ptr [ESI + 0x240]
    //         004e7d8f     PUSH       this
    //         004e7d90     MOV        this,dword ptr [EDI + 0x238]
    //         004e7d96     PUSH       0x8f
    //         004e7d9b     ADD        this,0x1146c
    //         004e7da1     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:565 (12)
    //         004e7da6     MOV        EDX,dword ptr [ESI + 0x28c]
    //         004e7dac     PUSH       EDX
    //         004e7dad     PUSH       0xa2
    //                              taistrmd.cpp:566 (5)
    //         004e7db2     JMP        LAB_004e8c20
    //                               switchD_004e76b7::caseD_c                                    XREF[2]:     004e76b7(j), 004e8c70(*)  
    //                              taistrmd.cpp:570 (16)
    //         004e7db7     MOV        EAX,dword ptr [ESI + 0x4c]
    //         004e7dba     MOV        this,dword ptr [ESP + param_1]
    //         004e7dbe     PUSH       EAX
    //         004e7dbf     PUSH       0x12
    //         004e7dc1     MOV        this,dword ptr [ECX + this+0x238]
    //                              taistrmd.cpp:571 (5)
    //         004e7dc7     JMP        LAB_004e8c26
    //                               switchD_004e76b7::caseD_d                                    XREF[2]:     004e76b7(j), 004e8c74(*)  
    //                              taistrmd.cpp:576 (16)
    //         004e7dcc     MOV        EDX,dword ptr [ESI + 0x50]
    //         004e7dcf     MOV        EAX,dword ptr [ESP + param_1]
    //         004e7dd3     PUSH       EDX
    //         004e7dd4     PUSH       0x13
    //         004e7dd6     MOV        this,dword ptr [EAX + 0x238]
    //                              taistrmd.cpp:577 (5)
    //         004e7ddc     JMP        LAB_004e8c26
    //                               switchD_004e76b7::caseD_e                                    XREF[2]:     004e76b7(j), 004e8c78(*)  
    //                              taistrmd.cpp:582 (16)
    //         004e7de1     MOV        this,dword ptr [ESI + 0x54]
    //         004e7de4     MOV        EDX,dword ptr [ESP + param_1]
    //         004e7de8     PUSH       this
    //         004e7de9     PUSH       0x14
    //         004e7deb     MOV        this,dword ptr [EDX + 0x238]
    //                              taistrmd.cpp:583 (5)
    //         004e7df1     JMP        LAB_004e8c26
    //                               switchD_004e76b7::caseD_10                                   XREF[2]:     004e76b7(j), 004e8c80(*)  
    //                              taistrmd.cpp:587 (27)
    //         004e7df6     MOV        EDI,dword ptr [ESP + param_1]
    //         004e7dfa     MOV        EAX,dword ptr [ESI + 0x5c]
    //         004e7dfd     PUSH       EAX
    //         004e7dfe     PUSH       0x16
    //         004e7e00     MOV        this,dword ptr [EDI + 0x238]
    //         004e7e06     ADD        this,0x1146c
    //         004e7e0c     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:589 (26)
    //         004e7e11     MOV        this,dword ptr [ESI + 0x124]
    //         004e7e17     PUSH       this
    //         004e7e18     MOV        this,dword ptr [EDI + 0x238]
    //         004e7e1e     PUSH       0x48
    //         004e7e20     ADD        this,0x1146c
    //         004e7e26     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:591 (26)
    //         004e7e2b     MOV        EDX,dword ptr [ESI + 0xe8]
    //         004e7e31     MOV        this,dword ptr [EDI + 0x238]
    //         004e7e37     PUSH       EDX
    //         004e7e38     PUSH       0x39
    //         004e7e3a     ADD        this,0x1146c
    //         004e7e40     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:593 (9)
    //         004e7e45     MOV        EAX,dword ptr [ESI + 0x174]
    //         004e7e4b     PUSH       EAX
    //         004e7e4c     PUSH       0x5c
    //                              taistrmd.cpp:594 (5)
    //         004e7e4e     JMP        LAB_004e8c20
    //                               switchD_004e76b7::caseD_11                                   XREF[2]:     004e76b7(j), 004e8c84(*)  
    //                              taistrmd.cpp:598 (16)
    //         004e7e53     MOV        this,dword ptr [ESI + 0x60]
    //         004e7e56     MOV        EDX,dword ptr [ESP + param_1]
    //         004e7e5a     PUSH       this
    //         004e7e5b     PUSH       0x17
    //         004e7e5d     MOV        this,dword ptr [EDX + 0x238]
    //                              taistrmd.cpp:599 (5)
    //         004e7e63     JMP        LAB_004e8c26
    //                               switchD_004e76b7::caseD_12                                   XREF[2]:     004e76b7(j), 004e8c88(*)  
    //                              taistrmd.cpp:603 (16)
    //         004e7e68     MOV        EAX,dword ptr [ESI + 0x64]
    //         004e7e6b     MOV        this,dword ptr [ESP + param_1]
    //         004e7e6f     PUSH       EAX
    //         004e7e70     PUSH       0x18
    //         004e7e72     MOV        this,dword ptr [ECX + this+0x238]
    //                              taistrmd.cpp:604 (5)
    //         004e7e78     JMP        LAB_004e8c26
    //                               switchD_004e76b7::caseD_15                                   XREF[2]:     004e76b7(j), 004e8c94(*)  
    //                              taistrmd.cpp:608 (27)
    //         004e7e7d     MOV        EDI,dword ptr [ESP + param_1]
    //         004e7e81     MOV        EDX,dword ptr [ESI + 0x68]
    //         004e7e84     PUSH       EDX
    //         004e7e85     PUSH       0x19
    //         004e7e87     MOV        this,dword ptr [EDI + 0x238]
    //         004e7e8d     ADD        this,0x1146c
    //         004e7e93     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:610 (23)
    //         004e7e98     MOV        EAX,dword ptr [ESI + 0x74]
    //         004e7e9b     MOV        this,dword ptr [EDI + 0x238]
    //         004e7ea1     PUSH       EAX
    //         004e7ea2     PUSH       0x1c
    //         004e7ea4     ADD        this,0x1146c
    //         004e7eaa     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:612 (26)
    //         004e7eaf     MOV        this,dword ptr [ESI + 0x9c]
    //         004e7eb5     PUSH       this
    //         004e7eb6     MOV        this,dword ptr [EDI + 0x238]
    //         004e7ebc     PUSH       0x26
    //         004e7ebe     ADD        this,0x1146c
    //         004e7ec4     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:614 (9)
    //         004e7ec9     MOV        EDX,dword ptr [ESI + 0xa0]
    //         004e7ecf     PUSH       EDX
    //         004e7ed0     PUSH       0x27
    //                              taistrmd.cpp:615 (5)
    //         004e7ed2     JMP        LAB_004e8c20
    //                               switchD_004e76b7::caseD_16                                   XREF[2]:     004e76b7(j), 004e8c98(*)  
    //                              taistrmd.cpp:619 (16)
    //         004e7ed7     MOV        EAX,dword ptr [ESI + 0x78]
    //         004e7eda     MOV        this,dword ptr [ESP + param_1]
    //         004e7ede     PUSH       EAX
    //         004e7edf     PUSH       0x1d
    //         004e7ee1     MOV        this,dword ptr [ECX + this+0x238]
    //                              taistrmd.cpp:620 (5)
    //         004e7ee7     JMP        LAB_004e8c26
    //                               switchD_004e76b7::caseD_17                                   XREF[2]:     004e76b7(j), 004e8c9c(*)  
    //                              taistrmd.cpp:625 (30)
    //         004e7eec     MOV        EDI,dword ptr [ESP + param_1]
    //         004e7ef0     MOV        EDX,dword ptr [ESI + 0x84]
    //         004e7ef6     PUSH       EDX
    //         004e7ef7     PUSH       0x20
    //         004e7ef9     MOV        this,dword ptr [EDI + 0x238]
    //         004e7eff     ADD        this,0x1146c
    //         004e7f05     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:627 (12)
    //         004e7f0a     MOV        EAX,dword ptr [ESI + 0x248]
    //         004e7f10     PUSH       EAX
    //         004e7f11     PUSH       0x91
    //                              taistrmd.cpp:628 (5)
    //         004e7f16     JMP        LAB_004e8c20
    //                               switchD_004e76b7::caseD_18                                   XREF[2]:     004e76b7(j), 004e8ca0(*)  
    //                              taistrmd.cpp:632 (19)
    //         004e7f1b     MOV        this,dword ptr [ESI + 0x8c]
    //         004e7f21     MOV        EDX,dword ptr [ESP + param_1]
    //         004e7f25     PUSH       this
    //         004e7f26     PUSH       0x22
    //         004e7f28     MOV        this,dword ptr [EDX + 0x238]
    //                              taistrmd.cpp:633 (5)
    //         004e7f2e     JMP        LAB_004e8c26
    //                               switchD_004e76b7::caseD_19                                   XREF[2]:     004e76b7(j), 004e8ca4(*)  
    //                              taistrmd.cpp:637 (30)
    //         004e7f33     MOV        EDI,dword ptr [ESP + param_1]
    //         004e7f37     MOV        EAX,dword ptr [ESI + 0xa4]
    //         004e7f3d     PUSH       EAX
    //         004e7f3e     PUSH       0x28
    //         004e7f40     MOV        this,dword ptr [EDI + 0x238]
    //         004e7f46     ADD        this,0x1146c
    //         004e7f4c     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:639 (9)
    //         004e7f51     MOV        this,dword ptr [ESI + 0x130]
    //         004e7f57     PUSH       this
    //         004e7f58     PUSH       0x4b
    //                              taistrmd.cpp:640 (5)
    //         004e7f5a     JMP        LAB_004e8c20
    //                               switchD_004e76b7::caseD_1a                                   XREF[2]:     004e76b7(j), 004e8ca8(*)  
    //                              taistrmd.cpp:644 (19)
    //         004e7f5f     MOV        EDX,dword ptr [ESI + 0xa8]
    //         004e7f65     MOV        EAX,dword ptr [ESP + param_1]
    //         004e7f69     PUSH       EDX
    //         004e7f6a     PUSH       0x29
    //         004e7f6c     MOV        this,dword ptr [EAX + 0x238]
    //                              taistrmd.cpp:645 (5)
    //         004e7f72     JMP        LAB_004e8c26
    //                               switchD_004e76b7::caseD_1b                                   XREF[2]:     004e76b7(j), 004e8cac(*)  
    //                              taistrmd.cpp:649 (30)
    //         004e7f77     MOV        EDI,dword ptr [ESP + param_1]
    //         004e7f7b     MOV        this,dword ptr [ESI + 0xb0]
    //         004e7f81     PUSH       this
    //         004e7f82     PUSH       0x2b
    //         004e7f84     MOV        this,dword ptr [EDI + 0x238]
    //         004e7f8a     ADD        this,0x1146c
    //         004e7f90     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:651 (26)
    //         004e7f95     MOV        EDX,dword ptr [ESI + 0xb4]
    //         004e7f9b     MOV        this,dword ptr [EDI + 0x238]
    //         004e7fa1     PUSH       EDX
    //         004e7fa2     PUSH       0x2c
    //         004e7fa4     ADD        this,0x1146c
    //         004e7faa     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:653 (26)
    //         004e7faf     MOV        EAX,dword ptr [ESI + 0xac]
    //         004e7fb5     MOV        this,dword ptr [EDI + 0x238]
    //         004e7fbb     PUSH       EAX
    //         004e7fbc     PUSH       0x2a
    //         004e7fbe     ADD        this,0x1146c
    //         004e7fc4     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:655 (9)
    //         004e7fc9     MOV        this,dword ptr [ESI + 0xb8]
    //         004e7fcf     PUSH       this
    //         004e7fd0     PUSH       0x2d
    //                              taistrmd.cpp:656 (5)
    //         004e7fd2     JMP        LAB_004e8c20
    //                               switchD_004e76b7::caseD_1c                                   XREF[2]:     004e76b7(j), 004e8cb0(*)  
    //                              taistrmd.cpp:660 (27)
    //         004e7fd7     MOV        EDI,dword ptr [ESP + param_1]
    //         004e7fdb     MOV        EDX,dword ptr [ESI + 0x7c]
    //         004e7fde     PUSH       EDX
    //         004e7fdf     PUSH       0x1e
    //         004e7fe1     MOV        this,dword ptr [EDI + 0x238]
    //         004e7fe7     ADD        this,0x1146c
    //         004e7fed     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:662 (26)
    //         004e7ff2     MOV        EAX,dword ptr [ESI + 0x80]
    //         004e7ff8     MOV        this,dword ptr [EDI + 0x238]
    //         004e7ffe     PUSH       EAX
    //         004e7fff     PUSH       0x1f
    //         004e8001     ADD        this,0x1146c
    //         004e8007     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:664 (26)
    //         004e800c     MOV        this,dword ptr [ESI + 0x170]
    //         004e8012     PUSH       this
    //         004e8013     MOV        this,dword ptr [EDI + 0x238]
    //         004e8019     PUSH       0x5b
    //         004e801b     ADD        this,0x1146c
    //         004e8021     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:666 (26)
    //         004e8026     MOV        EDX,dword ptr [ESI + 0x180]
    //         004e802c     MOV        this,dword ptr [EDI + 0x238]
    //         004e8032     PUSH       EDX
    //         004e8033     PUSH       0x5f
    //         004e8035     ADD        this,0x1146c
    //         004e803b     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:668 (26)
    //         004e8040     MOV        EAX,dword ptr [ESI + 0x184]
    //         004e8046     MOV        this,dword ptr [EDI + 0x238]
    //         004e804c     PUSH       EAX
    //         004e804d     PUSH       0x60
    //         004e804f     ADD        this,0x1146c
    //         004e8055     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:670 (9)
    //         004e805a     MOV        this,dword ptr [ESI + 0x188]
    //         004e8060     PUSH       this
    //         004e8061     PUSH       0x61
    //                              taistrmd.cpp:671 (5)
    //         004e8063     JMP        LAB_004e8c20
    //                               switchD_004e76b7::caseD_1d                                   XREF[2]:     004e76b7(j), 004e8cb4(*)  
    //                              taistrmd.cpp:675 (30)
    //         004e8068     MOV        EDI,dword ptr [ESP + param_1]
    //         004e806c     MOV        EDX,dword ptr [ESI + 0xbc]
    //         004e8072     PUSH       EDX
    //         004e8073     PUSH       0x2e
    //         004e8075     MOV        this,dword ptr [EDI + 0x238]
    //         004e807b     ADD        this,0x1146c
    //         004e8081     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:677 (26)
    //         004e8086     MOV        EAX,dword ptr [ESI + 0x19c]
    //         004e808c     MOV        this,dword ptr [EDI + 0x238]
    //         004e8092     PUSH       EAX
    //                              language.dll match for 0x66: "Copperplate Gothic Light"
    //         004e8093     PUSH       0x66
    //         004e8095     ADD        this,0x1146c
    //         004e809b     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:679 (26)
    //         004e80a0     MOV        this,dword ptr [ESI + 0xc0]
    //         004e80a6     PUSH       this
    //         004e80a7     MOV        this,dword ptr [EDI + 0x238]
    //         004e80ad     PUSH       0x2f
    //         004e80af     ADD        this,0x1146c
    //         004e80b5     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:681 (26)
    //         004e80ba     MOV        EDX,dword ptr [ESI + 0x1a0]
    //         004e80c0     MOV        this,dword ptr [EDI + 0x238]
    //         004e80c6     PUSH       EDX
    //                              language.dll match for 0x67: "Comic Sans MS"
    //         004e80c7     PUSH       0x67
    //         004e80c9     ADD        this,0x1146c
    //         004e80cf     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:683 (26)
    //         004e80d4     MOV        EAX,dword ptr [ESI + 0x1a4]
    //         004e80da     MOV        this,dword ptr [EDI + 0x238]
    //         004e80e0     PUSH       EAX
    //                              language.dll match for 0x68: "Arial"
    //         004e80e1     PUSH       0x68
    //         004e80e3     ADD        this,0x1146c
    //         004e80e9     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:685 (12)
    //         004e80ee     MOV        this,dword ptr [ESI + 0x21c]
    //         004e80f4     PUSH       this
    //         004e80f5     PUSH       0x86
    //                              taistrmd.cpp:686 (5)
    //         004e80fa     JMP        LAB_004e8c20
    //                               switchD_004e76b7::caseD_1e                                   XREF[2]:     004e76b7(j), 004e8cb8(*)  
    //                              taistrmd.cpp:690 (19)
    //         004e80ff     MOV        EDX,dword ptr [ESI + 0xc4]
    //         004e8105     MOV        EAX,dword ptr [ESP + param_1]
    //         004e8109     PUSH       EDX
    //         004e810a     PUSH       0x30
    //         004e810c     MOV        this,dword ptr [EAX + 0x238]
    //                              taistrmd.cpp:691 (5)
    //         004e8112     JMP        LAB_004e8c26
    //                               switchD_004e76b7::caseD_1f                                   XREF[2]:     004e76b7(j), 004e8cbc(*)  
    //                              taistrmd.cpp:695 (30)
    //         004e8117     MOV        EDI,dword ptr [ESP + param_1]
    //         004e811b     MOV        this,dword ptr [ESI + 0xc8]
    //         004e8121     PUSH       this
    //         004e8122     PUSH       0x31
    //         004e8124     MOV        this,dword ptr [EDI + 0x238]
    //         004e812a     ADD        this,0x1146c
    //         004e8130     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:697 (29)
    //         004e8135     MOV        EDX,dword ptr [ESI + 0x220]
    //         004e813b     MOV        this,dword ptr [EDI + 0x238]
    //         004e8141     PUSH       EDX
    //         004e8142     PUSH       0x87
    //         004e8147     ADD        this,0x1146c
    //         004e814d     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:698 (29)
    //         004e8152     MOV        EAX,dword ptr [ESI + 0x224]
    //         004e8158     MOV        this,dword ptr [EDI + 0x238]
    //         004e815e     PUSH       EAX
    //         004e815f     PUSH       0x88
    //         004e8164     ADD        this,0x1146c
    //         004e816a     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:700 (12)
    //         004e816f     MOV        this,dword ptr [ESI + 0x324]
    //         004e8175     PUSH       this
    //         004e8176     PUSH       0xc8
    //                              taistrmd.cpp:701 (5)
    //         004e817b     JMP        LAB_004e8c20
    //                               switchD_004e76b7::caseD_20                                   XREF[2]:     004e76b7(j), 004e8cc0(*)  
    //                              taistrmd.cpp:705 (30)
    //         004e8180     MOV        EDI,dword ptr [ESP + param_1]
    //         004e8184     MOV        EDX,dword ptr [ESI + 0xcc]
    //         004e818a     PUSH       EDX
    //         004e818b     PUSH       0x32
    //         004e818d     MOV        this,dword ptr [EDI + 0x238]
    //         004e8193     ADD        this,0x1146c
    //         004e8199     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:707 (26)
    //         004e819e     MOV        EAX,dword ptr [ESI + 0xd0]
    //         004e81a4     MOV        this,dword ptr [EDI + 0x238]
    //         004e81aa     PUSH       EAX
    //         004e81ab     PUSH       0x33
    //         004e81ad     ADD        this,0x1146c
    //         004e81b3     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:709 (26)
    //         004e81b8     MOV        this,dword ptr [ESI + 0xd4]
    //         004e81be     PUSH       this
    //         004e81bf     MOV        this,dword ptr [EDI + 0x238]
    //         004e81c5     PUSH       0x34
    //         004e81c7     ADD        this,0x1146c
    //         004e81cd     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:711 (26)
    //         004e81d2     MOV        EDX,dword ptr [ESI + 0xd8]
    //         004e81d8     MOV        this,dword ptr [EDI + 0x238]
    //         004e81de     PUSH       EDX
    //         004e81df     PUSH       0x35
    //         004e81e1     ADD        this,0x1146c
    //         004e81e7     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:713 (26)
    //         004e81ec     MOV        EAX,dword ptr [ESI + 0xdc]
    //         004e81f2     MOV        this,dword ptr [EDI + 0x238]
    //         004e81f8     PUSH       EAX
    //         004e81f9     PUSH       0x36
    //         004e81fb     ADD        this,0x1146c
    //         004e8201     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:715 (26)
    //         004e8206     MOV        this,dword ptr [ESI + 0xe0]
    //         004e820c     PUSH       this
    //         004e820d     MOV        this,dword ptr [EDI + 0x238]
    //         004e8213     PUSH       0x37
    //         004e8215     ADD        this,0x1146c
    //         004e821b     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:717 (26)
    //         004e8220     MOV        EDX,dword ptr [ESI + 0xe4]
    //         004e8226     MOV        this,dword ptr [EDI + 0x238]
    //         004e822c     PUSH       EDX
    //         004e822d     PUSH       0x38
    //         004e822f     ADD        this,0x1146c
    //         004e8235     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:719 (9)
    //         004e823a     MOV        EAX,dword ptr [ESI + 0x11c]
    //         004e8240     PUSH       EAX
    //         004e8241     PUSH       0x46
    //                              taistrmd.cpp:720 (5)
    //         004e8243     JMP        LAB_004e8c20
    //                               switchD_004e76b7::caseD_21                                   XREF[2]:     004e76b7(j), 004e8cc4(*)  
    //                              taistrmd.cpp:725 (30)
    //         004e8248     MOV        EDI,dword ptr [ESP + param_1]
    //         004e824c     MOV        this,dword ptr [ESI + 0xec]
    //         004e8252     PUSH       this
    //         004e8253     PUSH       0x3a
    //         004e8255     MOV        this,dword ptr [EDI + 0x238]
    //         004e825b     ADD        this,0x1146c
    //         004e8261     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:727 (26)
    //         004e8266     MOV        EDX,dword ptr [ESI + 0xf0]
    //         004e826c     MOV        this,dword ptr [EDI + 0x238]
    //         004e8272     PUSH       EDX
    //         004e8273     PUSH       0x3b
    //         004e8275     ADD        this,0x1146c
    //         004e827b     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:729 (9)
    //         004e8280     MOV        EAX,dword ptr [ESI + 0xf4]
    //         004e8286     PUSH       EAX
    //         004e8287     PUSH       0x3c
    //                              taistrmd.cpp:730 (5)
    //         004e8289     JMP        LAB_004e8c20
    //                               switchD_004e76b7::caseD_22                                   XREF[2]:     004e76b7(j), 004e8cc8(*)  
    //                              taistrmd.cpp:735 (30)
    //         004e828e     MOV        EDI,dword ptr [ESP + param_1]
    //         004e8292     MOV        this,dword ptr [ESI + 0xf8]
    //         004e8298     PUSH       this
    //         004e8299     PUSH       0x3d
    //         004e829b     MOV        this,dword ptr [EDI + 0x238]
    //         004e82a1     ADD        this,0x1146c
    //         004e82a7     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:737 (26)
    //         004e82ac     MOV        EDX,dword ptr [ESI + 0xfc]
    //         004e82b2     MOV        this,dword ptr [EDI + 0x238]
    //         004e82b8     PUSH       EDX
    //         004e82b9     PUSH       0x3e
    //         004e82bb     ADD        this,0x1146c
    //         004e82c1     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:739 (9)
    //         004e82c6     MOV        EAX,dword ptr [ESI + 0x100]
    //         004e82cc     PUSH       EAX
    //         004e82cd     PUSH       0x3f
    //                              taistrmd.cpp:740 (5)
    //         004e82cf     JMP        LAB_004e8c20
    //                               switchD_004e76b7::caseD_23                                   XREF[2]:     004e76b7(j), 004e8ccc(*)  
    //                              taistrmd.cpp:745 (30)
    //         004e82d4     MOV        EDI,dword ptr [ESP + param_1]
    //         004e82d8     MOV        this,dword ptr [ESI + 0x104]
    //         004e82de     PUSH       this
    //         004e82df     PUSH       0x40
    //         004e82e1     MOV        this,dword ptr [EDI + 0x238]
    //         004e82e7     ADD        this,0x1146c
    //         004e82ed     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:747 (26)
    //         004e82f2     MOV        EDX,dword ptr [ESI + 0x108]
    //         004e82f8     MOV        this,dword ptr [EDI + 0x238]
    //         004e82fe     PUSH       EDX
    //         004e82ff     PUSH       0x41
    //         004e8301     ADD        this,0x1146c
    //         004e8307     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:749 (26)
    //         004e830c     MOV        EAX,dword ptr [ESI + 0x10c]
    //         004e8312     MOV        this,dword ptr [EDI + 0x238]
    //         004e8318     PUSH       EAX
    //         004e8319     PUSH       0x42
    //         004e831b     ADD        this,0x1146c
    //         004e8321     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:751 (12)
    //         004e8326     MOV        this,dword ptr [ESI + 0x364]
    //         004e832c     PUSH       this
    //         004e832d     PUSH       0xd8
    //                              taistrmd.cpp:752 (5)
    //         004e8332     JMP        LAB_004e8c20
    //                               switchD_004e76b7::caseD_24                                   XREF[2]:     004e76b7(j), 004e8cd0(*)  
    //                              taistrmd.cpp:757 (30)
    //         004e8337     MOV        EDI,dword ptr [ESP + param_1]
    //         004e833b     MOV        EDX,dword ptr [ESI + 0x110]
    //         004e8341     PUSH       EDX
    //         004e8342     PUSH       0x43
    //         004e8344     MOV        this,dword ptr [EDI + 0x238]
    //         004e834a     ADD        this,0x1146c
    //         004e8350     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:759 (26)
    //         004e8355     MOV        EAX,dword ptr [ESI + 0x114]
    //         004e835b     MOV        this,dword ptr [EDI + 0x238]
    //         004e8361     PUSH       EAX
    //         004e8362     PUSH       0x44
    //         004e8364     ADD        this,0x1146c
    //         004e836a     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:761 (9)
    //         004e836f     MOV        this,dword ptr [ESI + 0x118]
    //         004e8375     PUSH       this
    //         004e8376     PUSH       0x45
    //                              taistrmd.cpp:762 (5)
    //         004e8378     JMP        LAB_004e8c20
    //                               switchD_004e76b7::caseD_25                                   XREF[2]:     004e76b7(j), 004e8cd4(*)  
    //                              taistrmd.cpp:767 (19)
    //         004e837d     MOV        EDX,dword ptr [ESI + 0x120]
    //         004e8383     MOV        EAX,dword ptr [ESP + param_1]
    //         004e8387     PUSH       EDX
    //         004e8388     PUSH       0x47
    //         004e838a     MOV        this,dword ptr [EAX + 0x238]
    //                              taistrmd.cpp:768 (5)
    //         004e8390     JMP        LAB_004e8c26
    //                               switchD_004e76b7::caseD_26                                   XREF[2]:     004e76b7(j), 004e8cd8(*)  
    //                              taistrmd.cpp:773 (30)
    //         004e8395     MOV        EDI,dword ptr [ESP + param_1]
    //         004e8399     MOV        this,dword ptr [ESI + 0x128]
    //         004e839f     PUSH       this
    //         004e83a0     PUSH       0x49
    //         004e83a2     MOV        this,dword ptr [EDI + 0x238]
    //         004e83a8     ADD        this,0x1146c
    //         004e83ae     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:775 (9)
    //         004e83b3     MOV        EDX,dword ptr [ESI + 0x12c]
    //         004e83b9     PUSH       EDX
    //         004e83ba     PUSH       0x4a
    //                              taistrmd.cpp:776 (5)
    //         004e83bc     JMP        LAB_004e8c20
    //                               switchD_004e76b7::caseD_27                                   XREF[2]:     004e76b7(j), 004e8cdc(*)  
    //                              taistrmd.cpp:781 (19)
    //         004e83c1     MOV        EAX,dword ptr [ESI + 0x134]
    //         004e83c7     MOV        this,dword ptr [ESP + param_1]
    //         004e83cb     PUSH       EAX
    //         004e83cc     PUSH       0x4c
    //         004e83ce     MOV        this,dword ptr [ECX + this+0x238]
    //                              taistrmd.cpp:782 (5)
    //         004e83d4     JMP        LAB_004e8c26
    //                               switchD_004e76b7::caseD_28                                   XREF[2]:     004e76b7(j), 004e8ce0(*)  
    //                              taistrmd.cpp:787 (30)
    //         004e83d9     MOV        EDI,dword ptr [ESP + param_1]
    //         004e83dd     MOV        EDX,dword ptr [ESI + 0x138]
    //         004e83e3     PUSH       EDX
    //         004e83e4     PUSH       0x4d
    //         004e83e6     MOV        this,dword ptr [EDI + 0x238]
    //         004e83ec     ADD        this,0x1146c
    //         004e83f2     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:789 (26)
    //         004e83f7     MOV        EAX,dword ptr [ESI + 0x13c]
    //         004e83fd     MOV        this,dword ptr [EDI + 0x238]
    //         004e8403     PUSH       EAX
    //         004e8404     PUSH       0x4e
    //         004e8406     ADD        this,0x1146c
    //         004e840c     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:791 (26)
    //         004e8411     MOV        this,dword ptr [ESI + 0x140]
    //         004e8417     PUSH       this
    //         004e8418     MOV        this,dword ptr [EDI + 0x238]
    //         004e841e     PUSH       0x4f
    //         004e8420     ADD        this,0x1146c
    //         004e8426     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:793 (26)
    //         004e842b     MOV        EDX,dword ptr [ESI + 0x144]
    //         004e8431     MOV        this,dword ptr [EDI + 0x238]
    //         004e8437     PUSH       EDX
    //         004e8438     PUSH       0x50
    //         004e843a     ADD        this,0x1146c
    //         004e8440     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:795 (26)
    //         004e8445     MOV        EAX,dword ptr [ESI + 0x148]
    //         004e844b     MOV        this,dword ptr [EDI + 0x238]
    //         004e8451     PUSH       EAX
    //         004e8452     PUSH       0x51
    //         004e8454     ADD        this,0x1146c
    //         004e845a     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:797 (26)
    //         004e845f     MOV        this,dword ptr [ESI + 0x14c]
    //         004e8465     PUSH       this
    //         004e8466     MOV        this,dword ptr [EDI + 0x238]
    //         004e846c     PUSH       0x52
    //         004e846e     ADD        this,0x1146c
    //         004e8474     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:799 (26)
    //         004e8479     MOV        EDX,dword ptr [ESI + 0x150]
    //         004e847f     MOV        this,dword ptr [EDI + 0x238]
    //         004e8485     PUSH       EDX
    //         004e8486     PUSH       0x53
    //         004e8488     ADD        this,0x1146c
    //         004e848e     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:801 (26)
    //         004e8493     MOV        EAX,dword ptr [ESI + 0x168]
    //         004e8499     MOV        this,dword ptr [EDI + 0x238]
    //         004e849f     PUSH       EAX
    //         004e84a0     PUSH       0x59
    //         004e84a2     ADD        this,0x1146c
    //         004e84a8     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:803 (26)
    //         004e84ad     MOV        this,dword ptr [ESI + 0x16c]
    //         004e84b3     PUSH       this
    //         004e84b4     MOV        this,dword ptr [EDI + 0x238]
    //         004e84ba     PUSH       0x5a
    //         004e84bc     ADD        this,0x1146c
    //         004e84c2     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:805 (26)
    //         004e84c7     MOV        EDX,dword ptr [ESI + 0x1ac]
    //         004e84cd     MOV        this,dword ptr [EDI + 0x238]
    //         004e84d3     PUSH       EDX
    //         004e84d4     PUSH       0x6a
    //         004e84d6     ADD        this,0x1146c
    //         004e84dc     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:807 (26)
    //         004e84e1     MOV        EAX,dword ptr [ESI + 0x1b0]
    //         004e84e7     MOV        this,dword ptr [EDI + 0x238]
    //         004e84ed     PUSH       EAX
    //         004e84ee     PUSH       0x6b
    //         004e84f0     ADD        this,0x1146c
    //         004e84f6     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:809 (26)
    //         004e84fb     MOV        this,dword ptr [ESI + 0x1b4]
    //         004e8501     PUSH       this
    //         004e8502     MOV        this,dword ptr [EDI + 0x238]
    //         004e8508     PUSH       0x6c
    //         004e850a     ADD        this,0x1146c
    //         004e8510     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:811 (26)
    //         004e8515     MOV        EDX,dword ptr [ESI + 0x1b8]
    //         004e851b     MOV        this,dword ptr [EDI + 0x238]
    //         004e8521     PUSH       EDX
    //         004e8522     PUSH       0x6d
    //         004e8524     ADD        this,0x1146c
    //         004e852a     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:813 (26)
    //         004e852f     MOV        EAX,dword ptr [ESI + 0x1bc]
    //         004e8535     PUSH       EAX
    //         004e8536     MOV        this,dword ptr [EDI + 0x238]
    //                              language.dll match for 0x6e: "Copperplate Gothic Light"
    //         004e853c     PUSH       0x6e
    //         004e853e     ADD        this,0x1146c
    //         004e8544     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:815 (26)
    //         004e8549     MOV        this,dword ptr [ESI + 0x1c0]
    //         004e854f     PUSH       this
    //         004e8550     MOV        this,dword ptr [EDI + 0x238]
    //                              language.dll match for 0x6f: "12"
    //         004e8556     PUSH       0x6f
    //         004e8558     ADD        this,0x1146c
    //         004e855e     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:817 (26)
    //         004e8563     MOV        EDX,dword ptr [ESI + 0x1ec]
    //         004e8569     MOV        this,dword ptr [EDI + 0x238]
    //         004e856f     PUSH       EDX
    //                              language.dll match for 0x7a: "Arial"
    //         004e8570     PUSH       0x7a
    //         004e8572     ADD        this,0x1146c
    //         004e8578     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:819 (26)
    //         004e857d     MOV        EAX,dword ptr [ESI + 0x1f0]
    //         004e8583     MOV        this,dword ptr [EDI + 0x238]
    //         004e8589     PUSH       EAX
    //                              language.dll match for 0x7b: "9"
    //         004e858a     PUSH       0x7b
    //         004e858c     ADD        this,0x1146c
    //         004e8592     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:821 (29)
    //         004e8597     MOV        this,dword ptr [ESI + 0x244]
    //         004e859d     PUSH       this
    //         004e859e     MOV        this,dword ptr [EDI + 0x238]
    //         004e85a4     PUSH       0x90
    //         004e85a9     ADD        this,0x1146c
    //         004e85af     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:823 (29)
    //         004e85b4     MOV        EDX,dword ptr [ESI + 0x2e4]
    //         004e85ba     MOV        this,dword ptr [EDI + 0x238]
    //         004e85c0     PUSH       EDX
    //         004e85c1     PUSH       0xb8
    //         004e85c6     ADD        this,0x1146c
    //         004e85cc     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:825 (12)
    //         004e85d1     MOV        EAX,dword ptr [ESI + 0x2e8]
    //         004e85d7     PUSH       EAX
    //         004e85d8     PUSH       0xb9
    //                              taistrmd.cpp:826 (5)
    //         004e85dd     JMP        LAB_004e8c20
    //                               switchD_004e76b7::caseD_29                                   XREF[2]:     004e76b7(j), 004e8ce4(*)  
    //                              taistrmd.cpp:831 (30)
    //         004e85e2     MOV        EDI,dword ptr [ESP + param_1]
    //         004e85e6     MOV        this,dword ptr [ESI + 0x154]
    //         004e85ec     PUSH       this
    //         004e85ed     PUSH       0x54
    //         004e85ef     MOV        this,dword ptr [EDI + 0x238]
    //         004e85f5     ADD        this,0x1146c
    //         004e85fb     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:833 (26)
    //         004e8600     MOV        EDX,dword ptr [ESI + 0x158]
    //         004e8606     MOV        this,dword ptr [EDI + 0x238]
    //         004e860c     PUSH       EDX
    //         004e860d     PUSH       0x55
    //         004e860f     ADD        this,0x1146c
    //         004e8615     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:835 (12)
    //         004e861a     MOV        EAX,dword ptr [ESI + 0x228]
    //         004e8620     PUSH       EAX
    //         004e8621     PUSH       0x89
    //                              taistrmd.cpp:836 (5)
    //         004e8626     JMP        LAB_004e8c20
    //                               switchD_004e76b7::caseD_2a                                   XREF[2]:     004e76b7(j), 004e8ce8(*)  
    //                              taistrmd.cpp:841 (30)
    //         004e862b     MOV        EDI,dword ptr [ESP + param_1]
    //         004e862f     MOV        this,dword ptr [ESI + 0x15c]
    //         004e8635     PUSH       this
    //         004e8636     PUSH       0x56
    //         004e8638     MOV        this,dword ptr [EDI + 0x238]
    //         004e863e     ADD        this,0x1146c
    //         004e8644     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:843 (26)
    //         004e8649     MOV        EDX,dword ptr [ESI + 0x160]
    //         004e864f     MOV        this,dword ptr [EDI + 0x238]
    //         004e8655     PUSH       EDX
    //         004e8656     PUSH       0x57
    //         004e8658     ADD        this,0x1146c
    //         004e865e     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:845 (29)
    //         004e8663     MOV        EAX,dword ptr [ESI + 0x32c]
    //         004e8669     MOV        this,dword ptr [EDI + 0x238]
    //         004e866f     PUSH       EAX
    //         004e8670     PUSH       0xca
    //         004e8675     ADD        this,0x1146c
    //         004e867b     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:847 (29)
    //         004e8680     MOV        this,dword ptr [ESI + 0x25c]
    //         004e8686     PUSH       this
    //         004e8687     MOV        this,dword ptr [EDI + 0x238]
    //         004e868d     PUSH       0x96
    //         004e8692     ADD        this,0x1146c
    //         004e8698     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:849 (29)
    //         004e869d     MOV        EDX,dword ptr [ESI + 0x260]
    //         004e86a3     MOV        this,dword ptr [EDI + 0x238]
    //         004e86a9     PUSH       EDX
    //         004e86aa     PUSH       0x97
    //         004e86af     ADD        this,0x1146c
    //         004e86b5     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:851 (29)
    //         004e86ba     MOV        EAX,dword ptr [ESI + 0x264]
    //         004e86c0     MOV        this,dword ptr [EDI + 0x238]
    //         004e86c6     PUSH       EAX
    //         004e86c7     PUSH       0x98
    //         004e86cc     ADD        this,0x1146c
    //         004e86d2     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:853 (29)
    //         004e86d7     MOV        this,dword ptr [ESI + 0x288]
    //         004e86dd     PUSH       this
    //         004e86de     MOV        this,dword ptr [EDI + 0x238]
    //         004e86e4     PUSH       0xa1
    //         004e86e9     ADD        this,0x1146c
    //         004e86ef     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:855 (12)
    //         004e86f4     MOV        EDX,dword ptr [ESI + 0x2a4]
    //         004e86fa     PUSH       EDX
    //         004e86fb     PUSH       0xa8
    //                              taistrmd.cpp:856 (5)
    //         004e8700     JMP        LAB_004e8c20
    //                               switchD_004e76b7::caseD_2b                                   XREF[2]:     004e76b7(j), 004e8cec(*)  
    //                              taistrmd.cpp:861 (30)
    //         004e8705     MOV        EDI,dword ptr [ESP + param_1]
    //         004e8709     MOV        EAX,dword ptr [ESI + 0x164]
    //         004e870f     PUSH       EAX
    //         004e8710     PUSH       0x58
    //         004e8712     MOV        this,dword ptr [EDI + 0x238]
    //         004e8718     ADD        this,0x1146c
    //         004e871e     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:863 (26)
    //         004e8723     MOV        this,dword ptr [ESI + 0x198]
    //         004e8729     PUSH       this
    //         004e872a     MOV        this,dword ptr [EDI + 0x238]
    //                              language.dll match for 0x65: "1"
    //         004e8730     PUSH       0x65
    //         004e8732     ADD        this,0x1146c
    //         004e8738     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:865 (29)
    //         004e873d     MOV        EDX,dword ptr [ESI + 0x270]
    //         004e8743     MOV        this,dword ptr [EDI + 0x238]
    //         004e8749     PUSH       EDX
    //         004e874a     PUSH       0x9b
    //         004e874f     ADD        this,0x1146c
    //         004e8755     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:867 (29)
    //         004e875a     MOV        EAX,dword ptr [ESI + 0x2c0]
    //         004e8760     MOV        this,dword ptr [EDI + 0x238]
    //         004e8766     PUSH       EAX
    //         004e8767     PUSH       0xaf
    //         004e876c     ADD        this,0x1146c
    //         004e8772     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:869 (29)
    //         004e8777     MOV        this,dword ptr [ESI + 0x2c4]
    //         004e877d     PUSH       this
    //         004e877e     MOV        this,dword ptr [EDI + 0x238]
    //         004e8784     PUSH       0xb0
    //         004e8789     ADD        this,0x1146c
    //         004e878f     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:871 (29)
    //         004e8794     MOV        EDX,dword ptr [ESI + 0x2c8]
    //         004e879a     MOV        this,dword ptr [EDI + 0x238]
    //         004e87a0     PUSH       EDX
    //         004e87a1     PUSH       0xb1
    //         004e87a6     ADD        this,0x1146c
    //         004e87ac     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:874 (29)
    //         004e87b1     MOV        EAX,dword ptr [ESI + 0x2d8]
    //         004e87b7     MOV        this,dword ptr [EDI + 0x238]
    //         004e87bd     PUSH       EAX
    //         004e87be     PUSH       0xb5
    //         004e87c3     ADD        this,0x1146c
    //         004e87c9     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:876 (29)
    //         004e87ce     MOV        this,dword ptr [ESI + 0x2dc]
    //         004e87d4     PUSH       this
    //         004e87d5     MOV        this,dword ptr [EDI + 0x238]
    //         004e87db     PUSH       0xb6
    //         004e87e0     ADD        this,0x1146c
    //         004e87e6     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:878 (29)
    //         004e87eb     MOV        EDX,dword ptr [ESI + 0x2e0]
    //         004e87f1     MOV        this,dword ptr [EDI + 0x238]
    //         004e87f7     PUSH       EDX
    //         004e87f8     PUSH       0xb7
    //         004e87fd     ADD        this,0x1146c
    //         004e8803     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:881 (29)
    //         004e8808     MOV        EAX,dword ptr [ESI + 0x2ec]
    //         004e880e     MOV        this,dword ptr [EDI + 0x238]
    //         004e8814     PUSH       EAX
    //         004e8815     PUSH       0xba
    //         004e881a     ADD        this,0x1146c
    //         004e8820     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:883 (29)
    //         004e8825     MOV        this,dword ptr [ESI + 0x2f0]
    //         004e882b     PUSH       this
    //         004e882c     MOV        this,dword ptr [EDI + 0x238]
    //         004e8832     PUSH       0xbb
    //         004e8837     ADD        this,0x1146c
    //         004e883d     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:885 (29)
    //         004e8842     MOV        EDX,dword ptr [ESI + 0x30c]
    //         004e8848     MOV        this,dword ptr [EDI + 0x238]
    //         004e884e     PUSH       EDX
    //         004e884f     PUSH       0xc2
    //         004e8854     ADD        this,0x1146c
    //         004e885a     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:887 (29)
    //         004e885f     MOV        EAX,dword ptr [ESI + 0x314]
    //         004e8865     MOV        this,dword ptr [EDI + 0x238]
    //         004e886b     PUSH       EAX
    //         004e886c     PUSH       0xc4
    //         004e8871     ADD        this,0x1146c
    //         004e8877     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:889 (29)
    //         004e887c     MOV        this,dword ptr [ESI + 0x318]
    //         004e8882     PUSH       this
    //         004e8883     MOV        this,dword ptr [EDI + 0x238]
    //         004e8889     PUSH       0xc5
    //         004e888e     ADD        this,0x1146c
    //         004e8894     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:892 (29)
    //         004e8899     MOV        EDX,dword ptr [ESI + 0x2f4]
    //         004e889f     MOV        this,dword ptr [EDI + 0x238]
    //         004e88a5     PUSH       EDX
    //         004e88a6     PUSH       0xbc
    //         004e88ab     ADD        this,0x1146c
    //         004e88b1     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:894 (29)
    //         004e88b6     MOV        EAX,dword ptr [ESI + 0x310]
    //         004e88bc     MOV        this,dword ptr [EDI + 0x238]
    //         004e88c2     PUSH       EAX
    //         004e88c3     PUSH       0xc3
    //         004e88c8     ADD        this,0x1146c
    //         004e88ce     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:897 (29)
    //         004e88d3     MOV        this,dword ptr [ESI + 0x2f8]
    //         004e88d9     PUSH       this
    //         004e88da     MOV        this,dword ptr [EDI + 0x238]
    //         004e88e0     PUSH       0xbd
    //         004e88e5     ADD        this,0x1146c
    //         004e88eb     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:899 (29)
    //         004e88f0     MOV        EDX,dword ptr [ESI + 0x31c]
    //         004e88f6     MOV        this,dword ptr [EDI + 0x238]
    //         004e88fc     PUSH       EDX
    //         004e88fd     PUSH       0xc6
    //         004e8902     ADD        this,0x1146c
    //         004e8908     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:901 (29)
    //         004e890d     MOV        EAX,dword ptr [ESI + 0x320]
    //         004e8913     MOV        this,dword ptr [EDI + 0x238]
    //         004e8919     PUSH       EAX
    //         004e891a     PUSH       0xc7
    //         004e891f     ADD        this,0x1146c
    //         004e8925     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:904 (29)
    //         004e892a     MOV        this,dword ptr [ESI + 0x360]
    //         004e8930     PUSH       this
    //         004e8931     MOV        this,dword ptr [EDI + 0x238]
    //         004e8937     PUSH       0xd7
    //         004e893c     ADD        this,0x1146c
    //         004e8942     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:906 (29)
    //         004e8947     MOV        EDX,dword ptr [ESI + 0x368]
    //         004e894d     MOV        this,dword ptr [EDI + 0x238]
    //         004e8953     PUSH       EDX
    //         004e8954     PUSH       0xd9
    //         004e8959     ADD        this,0x1146c
    //         004e895f     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:909 (29)
    //         004e8964     MOV        EAX,dword ptr [ESI + 0x36c]
    //         004e896a     MOV        this,dword ptr [EDI + 0x238]
    //         004e8970     PUSH       EAX
    //         004e8971     PUSH       0xda
    //         004e8976     ADD        this,0x1146c
    //         004e897c     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:911 (29)
    //         004e8981     MOV        this,dword ptr [ESI + 0x370]
    //         004e8987     PUSH       this
    //         004e8988     MOV        this,dword ptr [EDI + 0x238]
    //         004e898e     PUSH       0xdb
    //         004e8993     ADD        this,0x1146c
    //         004e8999     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:914 (12)
    //         004e899e     MOV        EDX,dword ptr [ESI + 0x378]
    //         004e89a4     PUSH       EDX
    //         004e89a5     PUSH       0xdd
    //                              taistrmd.cpp:915 (5)
    //         004e89aa     JMP        LAB_004e8c20
    //                               switchD_004e76b7::caseD_2c                                   XREF[2]:     004e76b7(j), 004e8cf0(*)  
    //                              taistrmd.cpp:920 (19)
    //         004e89af     MOV        EAX,dword ptr [ESI + 0x190]
    //         004e89b5     MOV        this,dword ptr [ESP + param_1]
    //         004e89b9     PUSH       EAX
    //         004e89ba     PUSH       0x63
    //         004e89bc     MOV        this,dword ptr [ECX + this+0x238]
    //                              taistrmd.cpp:921 (5)
    //         004e89c2     JMP        LAB_004e8c26
    //                               switchD_004e76b7::caseD_2d                                   XREF[2]:     004e76b7(j), 004e8cf4(*)  
    //                              taistrmd.cpp:926 (19)
    //         004e89c7     MOV        EDX,dword ptr [ESI + 0x1a8]
    //         004e89cd     MOV        EAX,dword ptr [ESP + param_1]
    //         004e89d1     PUSH       EDX
    //         004e89d2     PUSH       0x69
    //         004e89d4     MOV        this,dword ptr [EAX + 0x238]
    //                              taistrmd.cpp:927 (5)
    //         004e89da     JMP        LAB_004e8c26
    //                               switchD_004e76b7::caseD_2e                                   XREF[2]:     004e76b7(j), 004e8cf8(*)  
    //                              taistrmd.cpp:932 (19)
    //         004e89df     MOV        this,dword ptr [ESI + 0x1c4]
    //         004e89e5     MOV        EDX,dword ptr [ESP + param_1]
    //         004e89e9     PUSH       this
    //         004e89ea     PUSH       0x70
    //         004e89ec     MOV        this,dword ptr [EDX + 0x238]
    //                              taistrmd.cpp:933 (5)
    //         004e89f2     JMP        LAB_004e8c26
    //                               switchD_004e76b7::caseD_2f                                   XREF[2]:     004e76b7(j), 004e8cfc(*)  
    //                              taistrmd.cpp:937 (30)
    //         004e89f7     MOV        EDI,dword ptr [ESP + param_1]
    //         004e89fb     MOV        EAX,dword ptr [ESI + 0x1c8]
    //         004e8a01     PUSH       EAX
    //                              language.dll match for 0x71: "Copperplate Gothic Light"
    //         004e8a02     PUSH       0x71
    //         004e8a04     MOV        this,dword ptr [EDI + 0x238]
    //         004e8a0a     ADD        this,0x1146c
    //         004e8a10     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:939 (26)
    //         004e8a15     MOV        this,dword ptr [ESI + 0x1cc]
    //         004e8a1b     PUSH       this
    //         004e8a1c     MOV        this,dword ptr [EDI + 0x238]
    //                              language.dll match for 0x72: "21"
    //         004e8a22     PUSH       0x72
    //         004e8a24     ADD        this,0x1146c
    //         004e8a2a     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:940 (26)
    //         004e8a2f     MOV        EDX,dword ptr [ESI + 0x1d0]
    //         004e8a35     MOV        this,dword ptr [EDI + 0x238]
    //         004e8a3b     PUSH       EDX
    //                              language.dll match for 0x73: "B"
    //         004e8a3c     PUSH       0x73
    //         004e8a3e     ADD        this,0x1146c
    //         004e8a44     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:941 (26)
    //         004e8a49     MOV        EAX,dword ptr [ESI + 0x1d4]
    //         004e8a4f     MOV        this,dword ptr [EDI + 0x238]
    //         004e8a55     PUSH       EAX
    //                              language.dll match for 0x74: "Copperplate Gothic Light"
    //         004e8a56     PUSH       0x74
    //         004e8a58     ADD        this,0x1146c
    //         004e8a5e     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:942 (29)
    //         004e8a63     MOV        this,dword ptr [ESI + 0x24c]
    //         004e8a69     PUSH       this
    //         004e8a6a     MOV        this,dword ptr [EDI + 0x238]
    //         004e8a70     PUSH       0x92
    //         004e8a75     ADD        this,0x1146c
    //         004e8a7b     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:943 (12)
    //         004e8a80     MOV        EDX,dword ptr [ESI + 0x250]
    //         004e8a86     PUSH       EDX
    //         004e8a87     PUSH       0x93
    //                              taistrmd.cpp:944 (5)
    //         004e8a8c     JMP        LAB_004e8c20
    //                               switchD_004e76b7::caseD_30                                   XREF[2]:     004e76b7(j), 004e8d00(*)  
    //                              taistrmd.cpp:949 (30)
    //         004e8a91     MOV        EDI,dword ptr [ESP + param_1]
    //         004e8a95     MOV        EAX,dword ptr [ESI + 0x1f4]
    //         004e8a9b     PUSH       EAX
    //                              language.dll match for 0x7c: "B"
    //         004e8a9c     PUSH       0x7c
    //         004e8a9e     MOV        this,dword ptr [EDI + 0x238]
    //         004e8aa4     ADD        this,0x1146c
    //         004e8aaa     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:951 (26)
    //         004e8aaf     MOV        this,dword ptr [ESI + 0x1f8]
    //         004e8ab5     PUSH       this
    //         004e8ab6     MOV        this,dword ptr [EDI + 0x238]
    //                              language.dll match for 0x7d: "Arial"
    //         004e8abc     PUSH       0x7d
    //         004e8abe     ADD        this,0x1146c
    //         004e8ac4     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:953 (26)
    //         004e8ac9     MOV        EDX,dword ptr [ESI + 0x1fc]
    //         004e8acf     MOV        this,dword ptr [EDI + 0x238]
    //         004e8ad5     PUSH       EDX
    //                              language.dll match for 0x7e: "10"
    //         004e8ad6     PUSH       0x7e
    //         004e8ad8     ADD        this,0x1146c
    //         004e8ade     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:955 (26)
    //         004e8ae3     MOV        EAX,dword ptr [ESI + 0x200]
    //         004e8ae9     MOV        this,dword ptr [EDI + 0x238]
    //         004e8aef     PUSH       EAX
    //                              language.dll match for 0x7f: "N"
    //         004e8af0     PUSH       0x7f
    //         004e8af2     ADD        this,0x1146c
    //         004e8af8     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:957 (29)
    //         004e8afd     MOV        this,dword ptr [ESI + 0x204]
    //         004e8b03     PUSH       this
    //         004e8b04     MOV        this,dword ptr [EDI + 0x238]
    //                              language.dll match for 0x80: "Arial"
    //         004e8b0a     PUSH       0x80
    //         004e8b0f     ADD        this,0x1146c
    //         004e8b15     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:959 (29)
    //         004e8b1a     MOV        EDX,dword ptr [ESI + 0x208]
    //         004e8b20     MOV        this,dword ptr [EDI + 0x238]
    //         004e8b26     PUSH       EDX
    //                              language.dll match for 0x81: "10"
    //         004e8b27     PUSH       0x81
    //         004e8b2c     ADD        this,0x1146c
    //         004e8b32     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:961 (29)
    //         004e8b37     MOV        EAX,dword ptr [ESI + 0x20c]
    //         004e8b3d     MOV        this,dword ptr [EDI + 0x238]
    //         004e8b43     PUSH       EAX
    //                              language.dll match for 0x82: "B"
    //         004e8b44     PUSH       0x82
    //         004e8b49     ADD        this,0x1146c
    //         004e8b4f     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:963 (29)
    //         004e8b54     MOV        this,dword ptr [ESI + 0x214]
    //         004e8b5a     PUSH       this
    //         004e8b5b     MOV        this,dword ptr [EDI + 0x238]
    //                              language.dll match for 0x84: "8"
    //         004e8b61     PUSH       0x84
    //         004e8b66     ADD        this,0x1146c
    //         004e8b6c     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:965 (29)
    //         004e8b71     MOV        EDX,dword ptr [ESI + 0x218]
    //         004e8b77     MOV        this,dword ptr [EDI + 0x238]
    //         004e8b7d     PUSH       EDX
    //                              language.dll match for 0x85: "N"
    //         004e8b7e     PUSH       0x85
    //         004e8b83     ADD        this,0x1146c
    //         004e8b89     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:968 (29)
    //         004e8b8e     MOV        EAX,dword ptr [ESI + 0x2cc]
    //         004e8b94     MOV        this,dword ptr [EDI + 0x238]
    //         004e8b9a     PUSH       EAX
    //         004e8b9b     PUSH       0xb2
    //         004e8ba0     ADD        this,0x1146c
    //         004e8ba6     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:971 (12)
    //         004e8bab     MOV        this,dword ptr [ESI + 0x328]
    //         004e8bb1     PUSH       this
    //         004e8bb2     PUSH       0xc9
    //                              taistrmd.cpp:972 (2)
    //         004e8bb7     JMP        LAB_004e8c20
    //                               switchD_004e76b7::caseD_31                                   XREF[2]:     004e76b7(j), 004e8d04(*)  
    //                              taistrmd.cpp:976 (33)
    //         004e8bb9     MOV        EDI,dword ptr [ESP + param_1]
    //         004e8bbd     MOV        EDX,dword ptr [ESI + 0x22c]
    //         004e8bc3     PUSH       EDX
    //         004e8bc4     PUSH       0x8a
    //         004e8bc9     MOV        this,dword ptr [EDI + 0x238]
    //         004e8bcf     ADD        this,0x1146c
    //         004e8bd5     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:977 (29)
    //         004e8bda     MOV        EAX,dword ptr [ESI + 0x230]
    //         004e8be0     MOV        this,dword ptr [EDI + 0x238]
    //         004e8be6     PUSH       EAX
    //         004e8be7     PUSH       0x8b
    //         004e8bec     ADD        this,0x1146c
    //         004e8bf2     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:978 (29)
    //         004e8bf7     MOV        this,dword ptr [ESI + 0x234]
    //         004e8bfd     PUSH       this
    //         004e8bfe     MOV        this,dword ptr [EDI + 0x238]
    //         004e8c04     PUSH       0x8c
    //         004e8c09     ADD        this,0x1146c
    //         004e8c0f     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:979 (29)
    //         004e8c14     MOV        EDX,dword ptr [ESI + 0x238]
    //         004e8c1a     PUSH       EDX
    //         004e8c1b     PUSH       0x8d
    //                               LAB_004e8c20                                                 XREF[22]:    004e7c99(j), 004e7db2(j), 
    //                                                                                                         004e7e4e(j), 004e7ed2(j), 
    //                                                                                                         004e7f16(j), 004e7f5a(j), 
    //                                                                                                         004e7fd2(j), 004e8063(j), 
    //                                                                                                         004e80fa(j), 004e817b(j), 
    //                                                                                                         004e8243(j), 004e8289(j), 
    //                                                                                                         004e82cf(j), 004e8332(j), 
    //                                                                                                         004e8378(j), 004e83bc(j), 
    //                                                                                                         004e85dd(j), 004e8626(j), 
    //                                                                                                         004e8700(j), 004e89aa(j), [more]
    //         004e8c20     MOV        this,dword ptr [EDI + 0x238]
    //                               LAB_004e8c26                                                 XREF[14]:    004e7dc7(j), 004e7ddc(j), 
    //                                                                                                         004e7df1(j), 004e7e63(j), 
    //                                                                                                         004e7e78(j), 004e7ee7(j), 
    //                                                                                                         004e7f2e(j), 004e7f72(j), 
    //                                                                                                         004e8112(j), 004e8390(j), 
    //                                                                                                         004e83d4(j), 004e89c2(j), 
    //                                                                                                         004e89da(j), 004e89f2(j)  
    //         004e8c26     ADD        this,0x1146c
    //         004e8c2c     CALL       TribeTacticalAIModule::setStrategicNumber        void setStrategicNumber(TribeTacticalAIModule
    //                              taistrmd.cpp:980 (5)
    //         004e8c31     MOV        EAX,0x1
    //                              taistrmd.cpp:997 (210)
    //         004e8c36     POP        EDI
    //         004e8c37     POP        ESI
    //         004e8c38     RET        0xc
    //                               switchD_004e76b7::caseD_4                                    XREF[16]:    004e769a(j), 004e76a3(j), 
    //                               switchD_004e76b7::caseD_5                                                 004e76b1(j), 004e76b7(j), 
    //                               switchD_004e76b7::caseD_6                                                 004e8c4c(*), 004e8c50(*), 
    //                               switchD_004e76b7::caseD_7                                                 004e8c54(*), 004e8c58(*), 
    //                               switchD_004e76b7::caseD_8                                                 004e8c5c(*), 004e8c60(*), 
    //                               switchD_004e76b7::caseD_9                                                 004e8c64(*), 004e8c68(*), 
    //                               switchD_004e76b7::caseD_a                                                 004e8c6c(*), 004e8c7c(*), 
    //                               switchD_004e76b7::caseD_b                                                 004e8c8c(*), 004e8c90(*)  
    //                               switchD_004e76b7::caseD_f
    //                               switchD_004e76b7::caseD_13
    //                               switchD_004e76b7::caseD_14
    //                               switchD_004e76b7::caseD_3
    //         004e8c3b     POP        EDI
    //         004e8c3c     XOR        EAX,EAX
    //         004e8c3e     POP        ESI
    //         004e8c3f     RET        0xc
}

// Offset: 0x004E8C42
undefined FUN_004e8c42() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_004e8c42()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_004e8c42
    //         004e8c42     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004e76b7::switchdataD_004e8c44                       XREF[1]:     execute:004e76b7(*)  
}

// Offset: 0x004E8D10
int stopExecution(VictoryConditionRuleSystem* this_, TRIBE_Player* param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall VictoryConditionRuleSystem::stopExecution(class TRIBE_Player *,int)            *
    //                              *********************************************************************************************************
    //                              int __thiscall stopExecution(VictoryConditionRuleSystem * this, TRIB
    //              int               EAX:4          <RETURN>
    //              VictoryConditi    ECX:4 (auto)   this
    //              TRIBE_Player *    Stack[0x4]:4   param_1
    //              int               Stack[0x8]:4   param_2
    //                               ?stopExecution@VictoryConditionRuleSystem@@QAEHPAVTRIBE_Pla  XREF[1]:     update:004e9b90(c)  
    //                               VictoryConditionRuleSystem::stopExecution
    //                              taistrmd.cpp:1003 (2)
    //         004e8d10     XOR        EAX,EAX
    //                              taistrmd.cpp:1005 (3)
    //         004e8d12     RET        0x8
}

// Offset: 0x004E8D20
void modifyForDifficultyLevel(VictoryConditionRuleSystem* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall VictoryConditionRuleSystem::modifyForDifficultyLevel(int)                     *
    //                              *********************************************************************************************************
    //                              void __thiscall modifyForDifficultyLevel(VictoryConditionRuleSystem 
    //              void              <VOID>         <RETURN>
    //              VictoryConditi    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[2]:     004e8d20(R), 004e90b0(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[28]:    004e8e2c(W), 004e8e32(R), 004e8e58(W), 004e8e5e(R), 
    //                                                                                     004e8e7e(W), 004e8e84(R), 004e8ec0(W), 004e8ec6(R), 
    //                                                                                     004e8ee6(W), 004e8eec(R), 004e8f12(W), 004e8f20(R), 
    //                                                                                     004e8f40(W), 004e8f46(R), 004e8f69(W), 004e8f6f(R), 
    //                                                                                     004e8f98(W), 004e8f9e(R), 004e8fc7(W), 004e8fcd(R)  
    //              undefined4        Stack[-0x8]:4  local_8                   XREF[7]:     004e8d47(W), 004e8d7d(W), 004e8d9e(W), 004e8dc5(W), 
    //                                                                                     004e8dff(W), 004e8eca(R), 004e8ef0(R)  
    //              float             Stack[-0xc]:4  scale3                    XREF[17]:    004e8d3f(W), 004e8d70(W), 004e8d91(W), 004e8db8(W), 
    //                                                                                     004e8df2(W), 004e8e36(R), 004e8e62(R), 004e8e88(R), 
    //                                                                                     004e8f24(R), 004e8f4a(R), 004e8f73(R), 004e8fa2(R), 
    //                                                                                     004e8fd1(R), 004e9000(R), 004e902f(R), 004e905e(R), 
    //                                                                                     004e908d(R)  
    //              float             Stack[-0x10]:4 scale1
    //                               ?modifyForDifficultyLevel@VictoryConditionRuleSystem@@QAEXH@Z XREF[1]:     setDifficultyLevel:004ea1db(c)  
    //                               VictoryConditionRuleSystem::modifyForDifficultyLevel
    //                              taistrmd.cpp:1010 (21)
    //         004e8d20     MOV        EAX,dword ptr [ESP + param_1]
    //         004e8d24     SUB        ESP,0xc
    //         004e8d27     TEST       EAX,EAX
    //         004e8d29     PUSH       EBX
    //         004e8d2a     PUSH       EBP
    //         004e8d2b     PUSH       ESI
    //         004e8d2c     PUSH       EDI
    //         004e8d2d     MOV        ESI,this
    //         004e8d2f     JZ         switchD_004e8d55::default
    //                              taistrmd.cpp:1025 (2)
    //         004e8d35     XOR        EBX,EBX
    //                              taistrmd.cpp:1027 (2)
    //         004e8d37     XOR        EDI,EDI
    //                              taistrmd.cpp:1028 (2)
    //         004e8d39     XOR        EBP,EBP
    //                              taistrmd.cpp:1029 (33)
    //         004e8d3b     DEC        EAX
    //         004e8d3c     CMP        EAX,0x3
    //         004e8d3f     MOV        dword ptr [ESP + scale3],0x3f800000
    //         004e8d47     MOV        dword ptr [ESP + local_8],0x3f800000
    //         004e8d4f     JA         switchD_004e8d55::default
    //                               switchD_004e8d55::switchD
    //         004e8d55     JMP        dword ptr [EAX*0x4 + switchD_004e8d55::switchd   = 004e8d5c
    //                               switchD_004e8d55::caseD_1                                    XREF[2]:     004e8d55(j), 004e90ec(*)  
    //                              taistrmd.cpp:1033 (20)
    //         004e8d5c     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004e8d62     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
    //         004e8d67     CMP        EAX,0x1
    //         004e8d6a     JNZ        LAB_004e8e24
    //                              taistrmd.cpp:1034 (8)
    //         004e8d70     MOV        dword ptr [ESP + scale3],0x3f4ccccd
    //                              taistrmd.cpp:1035 (5)
    //         004e8d78     MOV        EBX,0x1e
    //                              taistrmd.cpp:1036 (8)
    //         004e8d7d     MOV        dword ptr [ESP + local_8],0x3f4ccccd
    //                              language.dll match for 0x78: "10"
    //                              taistrmd.cpp:1037 (5)
    //         004e8d85     MOV        EDI,0x78
    //                              taistrmd.cpp:1038 (2)
    //         004e8d8a     MOV        EBP,EAX
    //                              taistrmd.cpp:1040 (5)
    //         004e8d8c     JMP        LAB_004e8e24
    //                               switchD_004e8d55::caseD_2                                    XREF[2]:     004e8d55(j), 004e90f0(*)  
    //                              taistrmd.cpp:1042 (8)
    //         004e8d91     MOV        dword ptr [ESP + scale3],0x3f19999a
    //                              taistrmd.cpp:1043 (5)
    //         004e8d99     MOV        EBX,0x3c
    //                              taistrmd.cpp:1044 (8)
    //         004e8d9e     MOV        dword ptr [ESP + local_8],0x3f19999a
    //                              taistrmd.cpp:1045 (5)
    //         004e8da6     MOV        EDI,0xf0
    //                              taistrmd.cpp:1046 (5)
    //         004e8dab     MOV        EBP,0x2
    //                              taistrmd.cpp:1047 (2)
    //         004e8db0     JMP        LAB_004e8e24
    //                               switchD_004e8d55::caseD_3                                    XREF[2]:     004e8d55(j), 004e90f4(*)  
    //                              taistrmd.cpp:1053 (34)
    //         004e8db2     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004e8db8     MOV        dword ptr [ESP + scale3],0x3ecccccd
    //         004e8dc0     MOV        EBX,0x5a
    //         004e8dc5     MOV        dword ptr [ESP + local_8],0x3ecccccd
    //         004e8dcd     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
    //         004e8dd2     MOV        EDI,EAX
    //                              taistrmd.cpp:1057 (22)
    //         004e8dd4     MOV        EBP,0x3
    //         004e8dd9     DEC        EDI
    //         004e8dda     NEG        EDI
    //         004e8ddc     SBB        EDI,EDI
    //         004e8dde     AND        EDI,0x21c
    //         004e8de4     ADD        EDI,0x168
    //                              taistrmd.cpp:1058 (2)
    //         004e8dea     JMP        LAB_004e8e24
    //                               switchD_004e8d55::caseD_4                                    XREF[2]:     004e8d55(j), 004e90f8(*)  
    //                              taistrmd.cpp:1064 (34)
    //         004e8dec     MOV        this,dword ptr [rge_base_game]                   = 00000000
    //         004e8df2     MOV        dword ptr [ESP + scale3],0x3e4ccccd
    //                              language.dll match for 0x78: "10"
    //         004e8dfa     MOV        EBX,0x78
    //         004e8dff     MOV        dword ptr [ESP + local_8],0x3e4ccccd
    //         004e8e07     CALL       RGE_Base_Game::scenarioGame                      int scenarioGame(RGE_Base_Game * this)
    //         004e8e0c     MOV        EDI,EAX
    //                              taistrmd.cpp:1068 (22)
    //         004e8e0e     MOV        EBP,0x4
    //         004e8e13     DEC        EDI
    //         004e8e14     NEG        EDI
    //         004e8e16     SBB        EDI,EDI
    //         004e8e18     AND        EDI,0x30c
    //         004e8e1e     ADD        EDI,0x1e0
    //                               LAB_004e8e24                                                 XREF[4]:     004e8d6a(j), 004e8d8c(j), 
    //                                                                                                         004e8db0(j), 004e8dea(j)  
    //                              taistrmd.cpp:1075 (14)
    //         004e8e24     MOV        EAX,dword ptr [ESI + 0x94]
    //         004e8e2a     TEST       EAX,EAX
    //         004e8e2c     MOV        dword ptr [ESP + local_4],EAX
    //         004e8e30     JLE        LAB_004e8e53
    //                              taistrmd.cpp:1076 (13)
    //         004e8e32     FILD       dword ptr [ESP + local_4]
    //         004e8e36     FMUL       float ptr [ESP + scale3]
    //         004e8e3a     CALL       __ftol                                           undefined __ftol()
    //                              taistrmd.cpp:1077 (10)
    //         004e8e3f     TEST       EAX,EAX
    //         004e8e41     MOV        dword ptr [ESI + 0x94],EAX
    //         004e8e47     JNZ        LAB_004e8e53
    //                              taistrmd.cpp:1078 (10)
    //         004e8e49     MOV        dword ptr [ESI + 0x94],0x1
    //                               LAB_004e8e53                                                 XREF[2]:     004e8e30(j), 004e8e47(j)  
    //                              taistrmd.cpp:1081 (11)
    //         004e8e53     MOV        EAX,dword ptr [ESI + 0x44]
    //         004e8e56     TEST       EAX,EAX
    //         004e8e58     MOV        dword ptr [ESP + local_4],EAX
    //         004e8e5c     JLE        LAB_004e8e79
    //                              taistrmd.cpp:1082 (13)
    //         004e8e5e     FILD       dword ptr [ESP + local_4]
    //         004e8e62     FMUL       float ptr [ESP + scale3]
    //         004e8e66     CALL       __ftol                                           undefined __ftol()
    //                              taistrmd.cpp:1083 (7)
    //         004e8e6b     TEST       EAX,EAX
    //         004e8e6d     MOV        dword ptr [ESI + 0x44],EAX
    //         004e8e70     JNZ        LAB_004e8e79
    //                              taistrmd.cpp:1084 (7)
    //         004e8e72     MOV        dword ptr [ESI + 0x44],0x1
    //                               LAB_004e8e79                                                 XREF[2]:     004e8e5c(j), 004e8e70(j)  
    //                              taistrmd.cpp:1087 (11)
    //         004e8e79     MOV        EAX,dword ptr [ESI + 0x6c]
    //         004e8e7c     TEST       EAX,EAX
    //         004e8e7e     MOV        dword ptr [ESP + local_4],EAX
    //         004e8e82     JLE        LAB_004e8e9f
    //                              taistrmd.cpp:1088 (13)
    //         004e8e84     FILD       dword ptr [ESP + local_4]
    //         004e8e88     FMUL       float ptr [ESP + scale3]
    //         004e8e8c     CALL       __ftol                                           undefined __ftol()
    //                              taistrmd.cpp:1089 (7)
    //         004e8e91     TEST       EAX,EAX
    //         004e8e93     MOV        dword ptr [ESI + 0x6c],EAX
    //         004e8e96     JNZ        LAB_004e8e9f
    //                              taistrmd.cpp:1090 (7)
    //         004e8e98     MOV        dword ptr [ESI + 0x6c],0x1
    //                               LAB_004e8e9f                                                 XREF[2]:     004e8e82(j), 004e8e96(j)  
    //                              taistrmd.cpp:1093 (6)
    //         004e8e9f     MOV        EAX,dword ptr [ESI + 0xbc]
    //                              taistrmd.cpp:1094 (16)
    //         004e8ea5     MOV        EDX,dword ptr [ESI + 0xc4]
    //         004e8eab     ADD        EAX,EBX
    //         004e8ead     ADD        EDX,EBX
    //         004e8eaf     MOV        dword ptr [ESI + 0xbc],EAX
    //                              taistrmd.cpp:1096 (17)
    //         004e8eb5     MOV        EAX,dword ptr [ESI + 0x50]
    //         004e8eb8     TEST       EAX,EAX
    //         004e8eba     MOV        dword ptr [ESI + 0xc4],EDX
    //         004e8ec0     MOV        dword ptr [ESP + local_4],EAX
    //         004e8ec4     JLE        LAB_004e8ee1
    //                              taistrmd.cpp:1097 (13)
    //         004e8ec6     FILD       dword ptr [ESP + local_4]
    //         004e8eca     FMUL       float ptr [ESP + local_8]
    //         004e8ece     CALL       __ftol                                           undefined __ftol()
    //                              taistrmd.cpp:1098 (7)
    //         004e8ed3     TEST       EAX,EAX
    //         004e8ed5     MOV        dword ptr [ESI + 0x50],EAX
    //         004e8ed8     JNZ        LAB_004e8ee1
    //                              taistrmd.cpp:1099 (7)
    //         004e8eda     MOV        dword ptr [ESI + 0x50],0x1
    //                               LAB_004e8ee1                                                 XREF[2]:     004e8ec4(j), 004e8ed8(j)  
    //                              taistrmd.cpp:1101 (11)
    //         004e8ee1     MOV        EAX,dword ptr [ESI + 0x54]
    //         004e8ee4     TEST       EAX,EAX
    //         004e8ee6     MOV        dword ptr [ESP + local_4],EAX
    //         004e8eea     JLE        LAB_004e8f07
    //                              taistrmd.cpp:1102 (13)
    //         004e8eec     FILD       dword ptr [ESP + local_4]
    //         004e8ef0     FMUL       float ptr [ESP + local_8]
    //         004e8ef4     CALL       __ftol                                           undefined __ftol()
    //                              taistrmd.cpp:1103 (7)
    //         004e8ef9     TEST       EAX,EAX
    //         004e8efb     MOV        dword ptr [ESI + 0x54],EAX
    //         004e8efe     JNZ        LAB_004e8f07
    //                              taistrmd.cpp:1104 (7)
    //         004e8f00     MOV        dword ptr [ESI + 0x54],0x1
    //                               LAB_004e8f07                                                 XREF[2]:     004e8eea(j), 004e8efe(j)  
    //                              taistrmd.cpp:1107 (6)
    //         004e8f07     MOV        EDX,dword ptr [ESI + 0x1a4]
    //                              taistrmd.cpp:1109 (19)
    //         004e8f0d     MOV        EAX,dword ptr [ESI + 0x68]
    //         004e8f10     ADD        EDX,EDI
    //         004e8f12     MOV        dword ptr [ESP + local_4],EAX
    //         004e8f16     TEST       EAX,EAX
    //         004e8f18     MOV        dword ptr [ESI + 0x1a4],EDX
    //         004e8f1e     JLE        LAB_004e8f3b
    //                              taistrmd.cpp:1110 (13)
    //         004e8f20     FILD       dword ptr [ESP + local_4]
    //         004e8f24     FMUL       float ptr [ESP + scale3]
    //         004e8f28     CALL       __ftol                                           undefined __ftol()
    //                              taistrmd.cpp:1111 (7)
    //         004e8f2d     TEST       EAX,EAX
    //         004e8f2f     MOV        dword ptr [ESI + 0x68],EAX
    //         004e8f32     JNZ        LAB_004e8f3b
    //                              taistrmd.cpp:1112 (7)
    //         004e8f34     MOV        dword ptr [ESI + 0x68],0x1
    //                               LAB_004e8f3b                                                 XREF[2]:     004e8f1e(j), 004e8f32(j)  
    //                              taistrmd.cpp:1115 (11)
    //         004e8f3b     MOV        EAX,dword ptr [ESI + 0x74]
    //         004e8f3e     TEST       EAX,EAX
    //         004e8f40     MOV        dword ptr [ESP + local_4],EAX
    //         004e8f44     JLE        LAB_004e8f61
    //                              taistrmd.cpp:1116 (13)
    //         004e8f46     FILD       dword ptr [ESP + local_4]
    //         004e8f4a     FMUL       float ptr [ESP + scale3]
    //         004e8f4e     CALL       __ftol                                           undefined __ftol()
    //                              taistrmd.cpp:1117 (7)
    //         004e8f53     TEST       EAX,EAX
    //         004e8f55     MOV        dword ptr [ESI + 0x74],EAX
    //         004e8f58     JNZ        LAB_004e8f61
    //                              taistrmd.cpp:1118 (7)
    //         004e8f5a     MOV        dword ptr [ESI + 0x74],0x1
    //                               LAB_004e8f61                                                 XREF[2]:     004e8f44(j), 004e8f58(j)  
    //                              taistrmd.cpp:1121 (14)
    //         004e8f61     MOV        EAX,dword ptr [ESI + 0x9c]
    //         004e8f67     TEST       EAX,EAX
    //         004e8f69     MOV        dword ptr [ESP + local_4],EAX
    //         004e8f6d     JLE        LAB_004e8f90
    //                              taistrmd.cpp:1122 (13)
    //         004e8f6f     FILD       dword ptr [ESP + local_4]
    //         004e8f73     FMUL       float ptr [ESP + scale3]
    //         004e8f77     CALL       __ftol                                           undefined __ftol()
    //                              taistrmd.cpp:1123 (10)
    //         004e8f7c     TEST       EAX,EAX
    //         004e8f7e     MOV        dword ptr [ESI + 0x9c],EAX
    //         004e8f84     JNZ        LAB_004e8f90
    //                              taistrmd.cpp:1124 (10)
    //         004e8f86     MOV        dword ptr [ESI + 0x9c],0x1
    //                               LAB_004e8f90                                                 XREF[2]:     004e8f6d(j), 004e8f84(j)  
    //                              taistrmd.cpp:1127 (14)
    //         004e8f90     MOV        EAX,dword ptr [ESI + 0xec]
    //         004e8f96     TEST       EAX,EAX
    //         004e8f98     MOV        dword ptr [ESP + local_4],EAX
    //         004e8f9c     JLE        LAB_004e8fbf
    //                              taistrmd.cpp:1128 (13)
    //         004e8f9e     FILD       dword ptr [ESP + local_4]
    //         004e8fa2     FMUL       float ptr [ESP + scale3]
    //         004e8fa6     CALL       __ftol                                           undefined __ftol()
    //                              taistrmd.cpp:1129 (10)
    //         004e8fab     TEST       EAX,EAX
    //         004e8fad     MOV        dword ptr [ESI + 0xec],EAX
    //         004e8fb3     JNZ        LAB_004e8fbf
    //                              taistrmd.cpp:1130 (10)
    //         004e8fb5     MOV        dword ptr [ESI + 0xec],0x1
    //                               LAB_004e8fbf                                                 XREF[2]:     004e8f9c(j), 004e8fb3(j)  
    //                              taistrmd.cpp:1133 (14)
    //         004e8fbf     MOV        EAX,dword ptr [ESI + 0xf0]
    //         004e8fc5     TEST       EAX,EAX
    //         004e8fc7     MOV        dword ptr [ESP + local_4],EAX
    //         004e8fcb     JLE        LAB_004e8fee
    //                              taistrmd.cpp:1134 (13)
    //         004e8fcd     FILD       dword ptr [ESP + local_4]
    //         004e8fd1     FMUL       float ptr [ESP + scale3]
    //         004e8fd5     CALL       __ftol                                           undefined __ftol()
    //                              taistrmd.cpp:1135 (10)
    //         004e8fda     TEST       EAX,EAX
    //         004e8fdc     MOV        dword ptr [ESI + 0xf0],EAX
    //         004e8fe2     JNZ        LAB_004e8fee
    //                              taistrmd.cpp:1136 (10)
    //         004e8fe4     MOV        dword ptr [ESI + 0xf0],0x1
    //                               LAB_004e8fee                                                 XREF[2]:     004e8fcb(j), 004e8fe2(j)  
    //                              taistrmd.cpp:1139 (14)
    //         004e8fee     MOV        EAX,dword ptr [ESI + 0xf4]
    //         004e8ff4     TEST       EAX,EAX
    //         004e8ff6     MOV        dword ptr [ESP + local_4],EAX
    //         004e8ffa     JLE        LAB_004e901d
    //                              taistrmd.cpp:1140 (13)
    //         004e8ffc     FILD       dword ptr [ESP + local_4]
    //         004e9000     FMUL       float ptr [ESP + scale3]
    //         004e9004     CALL       __ftol                                           undefined __ftol()
    //                              taistrmd.cpp:1141 (10)
    //         004e9009     TEST       EAX,EAX
    //         004e900b     MOV        dword ptr [ESI + 0xf4],EAX
    //         004e9011     JNZ        LAB_004e901d
    //                              taistrmd.cpp:1142 (10)
    //         004e9013     MOV        dword ptr [ESI + 0xf4],0x1
    //                               LAB_004e901d                                                 XREF[2]:     004e8ffa(j), 004e9011(j)  
    //                              taistrmd.cpp:1145 (14)
    //         004e901d     MOV        EAX,dword ptr [ESI + 0x110]
    //         004e9023     TEST       EAX,EAX
    //         004e9025     MOV        dword ptr [ESP + local_4],EAX
    //         004e9029     JLE        LAB_004e904c
    //                              taistrmd.cpp:1146 (13)
    //         004e902b     FILD       dword ptr [ESP + local_4]
    //         004e902f     FMUL       float ptr [ESP + scale3]
    //         004e9033     CALL       __ftol                                           undefined __ftol()
    //                              taistrmd.cpp:1147 (10)
    //         004e9038     TEST       EAX,EAX
    //         004e903a     MOV        dword ptr [ESI + 0x110],EAX
    //         004e9040     JNZ        LAB_004e904c
    //                              taistrmd.cpp:1148 (10)
    //         004e9042     MOV        dword ptr [ESI + 0x110],0x1
    //                               LAB_004e904c                                                 XREF[2]:     004e9029(j), 004e9040(j)  
    //                              taistrmd.cpp:1151 (14)
    //         004e904c     MOV        EAX,dword ptr [ESI + 0x114]
    //         004e9052     TEST       EAX,EAX
    //         004e9054     MOV        dword ptr [ESP + local_4],EAX
    //         004e9058     JLE        LAB_004e907b
    //                              taistrmd.cpp:1152 (13)
    //         004e905a     FILD       dword ptr [ESP + local_4]
    //         004e905e     FMUL       float ptr [ESP + scale3]
    //         004e9062     CALL       __ftol                                           undefined __ftol()
    //                              taistrmd.cpp:1153 (10)
    //         004e9067     TEST       EAX,EAX
    //         004e9069     MOV        dword ptr [ESI + 0x114],EAX
    //         004e906f     JNZ        LAB_004e907b
    //                              taistrmd.cpp:1154 (10)
    //         004e9071     MOV        dword ptr [ESI + 0x114],0x1
    //                               LAB_004e907b                                                 XREF[2]:     004e9058(j), 004e906f(j)  
    //                              taistrmd.cpp:1157 (14)
    //         004e907b     MOV        EAX,dword ptr [ESI + 0x118]
    //         004e9081     TEST       EAX,EAX
    //         004e9083     MOV        dword ptr [ESP + local_4],EAX
    //         004e9087     JLE        LAB_004e90aa
    //                              taistrmd.cpp:1158 (13)
    //         004e9089     FILD       dword ptr [ESP + local_4]
    //         004e908d     FMUL       float ptr [ESP + scale3]
    //         004e9091     CALL       __ftol                                           undefined __ftol()
    //                              taistrmd.cpp:1159 (10)
    //         004e9096     TEST       EAX,EAX
    //         004e9098     MOV        dword ptr [ESI + 0x118],EAX
    //         004e909e     JNZ        LAB_004e90aa
    //                              taistrmd.cpp:1160 (10)
    //         004e90a0     MOV        dword ptr [ESI + 0x118],0x1
    //                               LAB_004e90aa                                                 XREF[2]:     004e9087(j), 004e909e(j)  
    //                              taistrmd.cpp:1163 (6)
    //         004e90aa     MOV        this,dword ptr [ESI + 0x164]
    //                              taistrmd.cpp:1168 (17)
    //         004e90b0     MOV        EAX,dword ptr [ESP + param_1]
    //         004e90b4     ADD        this,EBP
    //         004e90b6     CMP        EAX,0x3
    //         004e90b9     MOV        dword ptr [ESI + 0x164],this
    //         004e90bf     JG         LAB_004e90d5
    //                              taistrmd.cpp:1169 (10)
    //         004e90c1     MOV        dword ptr [ESI + 0x1a0],0x1
    //                              taistrmd.cpp:1172 (10)
    //         004e90cb     POP        EDI
    //         004e90cc     POP        ESI
    //         004e90cd     POP        EBP
    //         004e90ce     POP        EBX
    //         004e90cf     ADD        ESP,0xc
    //         004e90d2     RET        0x4
    //                               LAB_004e90d5                                                 XREF[1]:     004e90bf(j)  
    //                              taistrmd.cpp:1171 (10)
    //         004e90d5     MOV        dword ptr [ESI + 0x1a0],0x0
    //                               switchD_004e8d55::default                                    XREF[2]:     004e8d2f(j), 004e8d4f(j)  
    //                              taistrmd.cpp:1172 (29)
    //         004e90df     POP        EDI
    //         004e90e0     POP        ESI
    //         004e90e1     POP        EBP
    //         004e90e2     POP        EBX
    //         004e90e3     ADD        ESP,0xc
    //         004e90e6     RET        0x4
}

// Offset: 0x004E90E9
undefined FUN_004e90e9() {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              *                                               FUNCTION                                                *
    //                              *********************************************************************************************************
    //                              undefined FUN_004e90e9()
    //              undefined         <UNASSIGNED>   <RETURN>
    //                               FUN_004e90e9
    //         004e90e9     NOP
    //         004e90ea     MOV        EDI,EDI
    //                              Symbol Ref: No symbol: NONAME
    //                               switchD_004e8d55::switchdataD_004e90ec                       XREF[1]:     modifyForDifficultyLevel:004e8d55(
}

// Offset: 0x004E9100
undefined TribeStrategyAIModule(TribeStrategyAIModule* this_, void* param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TribeStrategyAIModule::TribeStrategyAIModule(void *,int)                           *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TribeStrategyAIModule(TribeStrategyAIModule * t
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeStrategyA    ECX:4 (auto)   this
    //              void *            Stack[0x4]:4   param_1                   XREF[1]:     004e911e(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004e9116(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[2]:     004e916c(W), 004e91be(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004e9226(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004e9128(W)  
    //                               ??0TribeStrategyAIModule@@QAE@PAXH@Z                         XREF[1]:     TribeMainDecisionAIModule:004e48c0
    //                               TribeStrategyAIModule::TribeStrategyAIModule
    //                              taistrmd.cpp:1189 (200)
    //         004e9100     PUSH       -0x1
    //         004e9102     PUSH       FUN_005607b2
    //         004e9107     MOV        EAX,FS:[0x0]
    //         004e910d     PUSH       EAX
    //         004e910e     MOV        dword ptr FS:[0x0],ESP
    //         004e9115     PUSH       this
    //         004e9116     MOV        EAX,dword ptr [ESP + param_2]
    //         004e911a     PUSH       EBX
    //         004e911b     PUSH       EBP
    //         004e911c     MOV        EBX,this
    //         004e911e     MOV        this,dword ptr [ESP + param_1]
    //         004e9122     PUSH       ESI
    //         004e9123     PUSH       EDI
    //         004e9124     PUSH       EAX
    //         004e9125     PUSH       this
    //         004e9126     MOV        this,EBX
    //         004e9128     MOV        dword ptr [ESP + local_10],EBX
    //         004e912c     CALL       StrategyAIModule::StrategyAIModule               undefined StrategyAIModule(StrategyAIModule *
    //         004e9131     XOR        ESI,ESI
    //         004e9133     OR         EBP,0xffffffff
    //         004e9136     MOV        dword ptr [EBX + 0xf0],ESI
    //         004e913c     MOV        dword ptr [EBX + 0xf4],EBP
    //         004e9142     MOV        dword ptr [EBX + 0x1fc],EBP
    //         004e9148     MOV        dword ptr [EBX + 0x200],EBP
    //         004e914e     MOV        dword ptr [EBX + 0x204],EBP
    //         004e9154     MOV        dword ptr [EBX + 0x208],EBP
    //         004e915a     MOV        dword ptr [EBX + 0x22c],EBP
    //         004e9160     MOV        dword ptr [EBX + 0x230],EBP
    //         004e9166     MOV        dword ptr [EBX + 0x234],ESI
    //         004e916c     MOV        dword ptr [ESP + local_4],ESI
    //         004e9170     MOV        dword ptr [EBX + 0x238],ESI
    //         004e9176     MOV        dword ptr [EBX + 0x23c],ESI
    //         004e917c     MOV        dword ptr [EBX + 0x240],ESI
    //         004e9182     MOV        dword ptr [EBX + 0x244],ESI
    //         004e9188     MOV        dword ptr [EBX + 0x248],ESI
    //         004e918e     MOV        dword ptr [EBX + 0x24c],ESI
    //         004e9194     MOV        dword ptr [EBX + 0x250],ESI
    //         004e919a     MOV        dword ptr [EBX + 0x254],ESI
    //         004e91a0     MOV        dword ptr [EBX + 0x258],ESI
    //         004e91a6     MOV        dword ptr [EBX + 0x25c],ESI
    //         004e91ac     MOV        dword ptr [EBX + 0x260],ESI
    //         004e91b2     MOV        dword ptr [EBX + 0x264],ESI
    //         004e91b8     LEA        this,[EBX + 0x268]
    //         004e91be     MOV        byte ptr [ESP + local_4],0x3
    //         004e91c3     CALL       VictoryConditionRuleSystem::VictoryConditionRu   undefined VictoryConditionRuleSystem(VictoryC
    //                              taistrmd.cpp:1190 (5)
    //         004e91c8     MOV        EAX,0xbf800000
    //                              taistrmd.cpp:1196 (82)
    //         004e91cd     MOV        EDI,s_                                           = ""
    //         004e91d2     MOV        dword ptr [EBX + 0x20c],EAX
    //         004e91d8     MOV        dword ptr [EBX + 0x210],EAX
    //         004e91de     MOV        dword ptr [EBX + 0x214],EAX
    //         004e91e4     MOV        dword ptr [EBX + 0x21c],EAX
    //         004e91ea     MOV        dword ptr [EBX + 0x220],EAX
    //         004e91f0     MOV        dword ptr [EBX + 0x224],EAX
    //         004e91f6     MOV        this,EBP
    //         004e91f8     XOR        EAX,EAX
    //         004e91fa     MOV        dword ptr [EBX + 0x5f4],ESI
    //         004e9200     MOV        dword ptr [EBX],TribeStrategyAIModule::`vftable' = 004e9240
    //         004e9206     SCASB.RE   ES:EDI=>s_                                       = ""
    //         004e9208     NOT        this
    //         004e920a     SUB        EDI,this
    //         004e920c     LEA        EDX,[EBX + 0xf8]
    //         004e9212     MOV        EAX,this
    //         004e9214     MOV        ESI,EDI
    //         004e9216     MOV        EDI,EDX
    //         004e9218     SHR        this,0x2
    //         004e921b     MOVSD.REP  ES:EDI,ESI
    //         004e921d     MOV        this,EAX
    //                              taistrmd.cpp:1197 (28)
    //         004e921f     MOV        EAX,EBX
    //         004e9221     AND        this,0x3
    //         004e9224     MOVSB.REP  ES:EDI,ESI
    //         004e9226     MOV        this,dword ptr [ESP + local_c]
    //         004e922a     POP        EDI
    //         004e922b     POP        ESI
    //         004e922c     POP        EBP
    //         004e922d     MOV        dword ptr FS:[0x0],this
    //         004e9234     POP        EBX
    //         004e9235     ADD        ESP,0x10
    //         004e9238     RET        0x8
}

// Offset: 0x004E9260
undefined TribeStrategyAIModule(TribeStrategyAIModule* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: __thiscall TribeStrategyAIModule::TribeStrategyAIModule(int,int)                              *
    //                              *********************************************************************************************************
    //                              undefined __thiscall TribeStrategyAIModule(TribeStrategyAIModule * t
    //              undefined         <UNASSIGNED>   <RETURN>
    //              TribeStrategyA    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[10]:    004e9278(R), 004e93c9(*), 004e93d6(R), 004e93eb(R), 
    //                                                                                     004e9430(*), 004e9443(R), 004e9534(*), 004e9547(R), 
    //                                                                                     004e963e(*), 004e9651(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[2]:     004e9302(R), 004e963a(R)  
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[3]:     004e9295(W), 004e92e7(W), 004e9307(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004e9718(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004e9286(W)  
    //              undefined4        Stack[-0x14]:4 local_14                  XREF[4]:     004e944e(W), 004e94e7(R), 004e9552(W), 004e95eb(R)  
    //              undefined4        Stack[-0x18]:4 local_18                  XREF[9]:     004e940c(*), 004e9419(R), 004e94ff(R), 004e9510(*), 
    //                                                                                     004e951d(R), 004e9603(R), 004e9614(*), 004e9621(R), 
    //                                                                                     004e9707(R)  
    //              int               Stack[-0x1c]:4 tempIntNum                XREF[9]:     004e9422(W), 004e94fb(R), 004e9506(W), 004e9526(W), 
    //                                                                                     004e95ff(R), 004e960a(W), 004e962a(W), 004e9703(R), 
    //                                                                                     004e970e(W)  
    //              int               Stack[-0x20]:4 i
    //                               ??0TribeStrategyAIModule@@QAE@HH@Z                           XREF[1]:     TribeMainDecisionAIModule:004e4c30
    //                               TribeStrategyAIModule::TribeStrategyAIModule
    //                              taistrmd.cpp:1205 (151)
    //         004e9260     PUSH       -0x1
    //         004e9262     PUSH       FUN_00560800
    //         004e9267     MOV        EAX,FS:[0x0]
    //         004e926d     PUSH       EAX
    //         004e926e     MOV        dword ptr FS:[0x0],ESP
    //         004e9275     SUB        ESP,0x10
    //         004e9278     MOV        EAX,dword ptr [ESP + param_1]
    //         004e927c     PUSH       EBX
    //         004e927d     PUSH       EBP
    //         004e927e     PUSH       ESI
    //         004e927f     PUSH       EDI
    //         004e9280     XOR        EBX,EBX
    //         004e9282     MOV        ESI,this
    //         004e9284     PUSH       EAX
    //         004e9285     PUSH       EBX
    //         004e9286     MOV        dword ptr [ESP + local_10],ESI
    //         004e928a     CALL       StrategyAIModule::StrategyAIModule               undefined StrategyAIModule(StrategyAIModule *
    //         004e928f     MOV        dword ptr [ESI + 0xf0],EBX
    //         004e9295     MOV        dword ptr [ESP + local_4],EBX
    //         004e9299     MOV        dword ptr [ESI + 0x238],EBX
    //         004e929f     MOV        dword ptr [ESI + 0x23c],EBX
    //         004e92a5     MOV        dword ptr [ESI + 0x240],EBX
    //         004e92ab     MOV        dword ptr [ESI + 0x244],EBX
    //         004e92b1     MOV        dword ptr [ESI + 0x248],EBX
    //         004e92b7     MOV        dword ptr [ESI + 0x24c],EBX
    //         004e92bd     MOV        dword ptr [ESI + 0x250],EBX
    //         004e92c3     MOV        dword ptr [ESI + 0x254],EBX
    //         004e92c9     MOV        dword ptr [ESI + 0x258],EBX
    //         004e92cf     MOV        dword ptr [ESI + 0x25c],EBX
    //         004e92d5     MOV        dword ptr [ESI + 0x260],EBX
    //         004e92db     MOV        dword ptr [ESI + 0x264],EBX
    //         004e92e1     LEA        this,[ESI + 0x268]
    //         004e92e7     MOV        byte ptr [ESP + local_4],0x3
    //         004e92ec     CALL       VictoryConditionRuleSystem::VictoryConditionRu   undefined VictoryConditionRuleSystem(VictoryC
    //         004e92f1     LEA        EDI,[ESI + 0x5f4]
    //                              taistrmd.cpp:1207 (35)
    //         004e92f7     LEA        this,[ESI + 0xf4]
    //         004e92fd     PUSH       0x4
    //         004e92ff     PUSH       this
    //         004e9300     MOV        dword ptr [EDI],EBX
    //         004e9302     MOV        EBX,dword ptr [ESP + param_2]
    //         004e9306     PUSH       EBX
    //         004e9307     MOV        byte ptr [ESP + local_4],0x4
    //         004e930c     MOV        dword ptr [ESI],TribeStrategyAIModule::`vftable' = 004e9240
    //         004e9312     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004e9317     ADD        ESP,0xc
    //                              taistrmd.cpp:1208 (18)
    //         004e931a     LEA        EDX,[ESI + 0x1fc]
    //         004e9320     PUSH       0x4
    //         004e9322     PUSH       EDX
    //         004e9323     PUSH       EBX
    //         004e9324     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004e9329     ADD        ESP,0xc
    //                              taistrmd.cpp:1209 (18)
    //         004e932c     LEA        EAX,[ESI + 0x204]
    //         004e9332     PUSH       0x4
    //         004e9334     PUSH       EAX
    //         004e9335     PUSH       EBX
    //         004e9336     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004e933b     ADD        ESP,0xc
    //                              taistrmd.cpp:1210 (18)
    //         004e933e     LEA        this,[ESI + 0x208]
    //         004e9344     PUSH       0x4
    //         004e9346     PUSH       this
    //         004e9347     PUSH       EBX
    //         004e9348     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004e934d     ADD        ESP,0xc
    //                              taistrmd.cpp:1211 (18)
    //         004e9350     LEA        EDX,[ESI + 0x20c]
    //         004e9356     PUSH       0x10
    //         004e9358     PUSH       EDX
    //         004e9359     PUSH       EBX
    //         004e935a     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004e935f     ADD        ESP,0xc
    //                              taistrmd.cpp:1212 (18)
    //         004e9362     LEA        EAX,[ESI + 0x21c]
    //         004e9368     PUSH       0x10
    //         004e936a     PUSH       EAX
    //         004e936b     PUSH       EBX
    //         004e936c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004e9371     ADD        ESP,0xc
    //                              taistrmd.cpp:1213 (18)
    //         004e9374     LEA        this,[ESI + 0x22c]
    //         004e937a     PUSH       0x4
    //         004e937c     PUSH       this
    //         004e937d     PUSH       EBX
    //         004e937e     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004e9383     ADD        ESP,0xc
    //                              taistrmd.cpp:1214 (18)
    //         004e9386     PUSH       0x4
    //         004e9388     LEA        EDX,[ESI + 0x230]
    //         004e938e     PUSH       EDX
    //         004e938f     PUSH       EBX
    //         004e9390     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004e9395     ADD        ESP,0xc
    //                              taistrmd.cpp:1215 (15)
    //         004e9398     LEA        EAX,[ESI + 0x234]
    //         004e939e     PUSH       0x4
    //         004e93a0     PUSH       EAX
    //         004e93a1     PUSH       EBX
    //         004e93a2     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              taistrmd.cpp:1216 (22)
    //         004e93a7     FLD        float ptr [save_game_version]                    = 7.23
    //         004e93ad     FCOMP      float ptr [DAT_00575690]
    //         004e93b3     ADD        ESP,0xc
    //         004e93b6     FNSTSW     AX
    //         004e93b8     TEST       AH,0x1
    //         004e93bb     JNZ        LAB_004e93c9
    //                              taistrmd.cpp:1217 (12)
    //         004e93bd     PUSH       0x4
    //         004e93bf     PUSH       EDI
    //         004e93c0     PUSH       EBX
    //         004e93c1     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //         004e93c6     ADD        ESP,0xc
    //                               LAB_004e93c9                                                 XREF[1]:     004e93bb(j)  
    //                              taistrmd.cpp:1220 (13)
    //         004e93c9     LEA        this=>param_1,[ESP + 0x30]
    //         004e93cd     PUSH       0x4
    //         004e93cf     PUSH       this
    //         004e93d0     PUSH       EBX
    //         004e93d1     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              taistrmd.cpp:1221 (21)
    //         004e93d6     MOV        EDX,dword ptr [ESP + param_1]
    //         004e93da     ADD        ESP,0xc
    //         004e93dd     LEA        EBP,[ESI + 0xf8]
    //         004e93e3     PUSH       EDX
    //         004e93e4     PUSH       EBP
    //         004e93e5     PUSH       EBX
    //         004e93e6     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              taistrmd.cpp:1222 (7)
    //         004e93eb     MOV        EAX,dword ptr [ESP + param_1]
    //         004e93ef     ADD        ESP,0xc
    //                              taistrmd.cpp:1223 (16)
    //         004e93f2     MOV        this,ESI
    //         004e93f4     PUSH       EBP
    //         004e93f5     MOV        byte ptr [EAX + ESI*0x1 + 0xf8],0x0
    //         004e93fd     CALL       TribeStrategyAIModule::loadRules                 int loadRules(TribeStrategyAIModule * this, c
    //                              taistrmd.cpp:1224 (10)
    //         004e9402     MOV        this,dword ptr [EDI]
    //         004e9404     PUSH       this
    //         004e9405     MOV        this,ESI
    //         004e9407     CALL       TribeStrategyAIModule::setDifficultyLevel        void setDifficultyLevel(TribeStrategyAIModule
    //                              taistrmd.cpp:1228 (13)
    //         004e940c     LEA        EDX=>local_18,[ESP + 0x14]
    //         004e9410     PUSH       0x4
    //         004e9412     PUSH       EDX
    //         004e9413     PUSH       EBX
    //         004e9414     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              taistrmd.cpp:1229 (23)
    //         004e9419     MOV        EAX,dword ptr [ESP + local_18]
    //         004e941d     ADD        ESP,0xc
    //         004e9420     TEST       EAX,EAX
    //         004e9422     MOV        dword ptr [ESP + tempIntNum],0x0
    //         004e942a     JLE        LAB_004e9510
    //                               LAB_004e9430                                                 XREF[1]:     004e950a(j)  
    //                              taistrmd.cpp:1230 (13)
    //         004e9430     LEA        EAX=>param_1,[ESP + 0x30]
    //         004e9434     PUSH       0x4
    //         004e9436     PUSH       EAX
    //         004e9437     PUSH       EBX
    //         004e9438     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              taistrmd.cpp:1231 (211)
    //         004e943d     MOV        this,dword ptr [ESI + 0x23c]
    //         004e9443     MOV        EDX,dword ptr [ESP + param_1]
    //         004e9447     ADD        ESP,0xc
    //         004e944a     XOR        EAX,EAX
    //         004e944c     TEST       this,this
    //         004e944e     MOV        dword ptr [ESP + local_14],EDX
    //         004e9452     JLE        LAB_004e9473
    //         004e9454     MOV        EDI,dword ptr [ESI + 0x244]
    //                               LAB_004e945a                                                 XREF[1]:     004e9471(j)  
    //         004e945a     CMP        EAX,EDI
    //         004e945c     JGE        LAB_004e9473
    //         004e945e     MOV        EBP,dword ptr [ESI + 0x238]
    //         004e9464     CMP        dword ptr [EBP + EAX*0x4],EDX
    //         004e9468     JZ         LAB_004e94fb
    //         004e946e     INC        EAX
    //         004e946f     CMP        EAX,this
    //         004e9471     JL         LAB_004e945a
    //                               LAB_004e9473                                                 XREF[2]:     004e9452(j), 004e945c(j)  
    //         004e9473     MOV        EDX,dword ptr [ESI + 0x244]
    //         004e9479     DEC        EDX
    //         004e947a     CMP        this,EDX
    //         004e947c     JLE        LAB_004e94db
    //         004e947e     LEA        EBP,[ECX + this+0x1]
    //         004e9481     LEA        EAX,[EBP*0x4 + 0x0]
    //         004e9488     PUSH       EAX
    //         004e9489     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004e948e     MOV        EDI,EAX
    //         004e9490     ADD        ESP,0x4
    //         004e9493     TEST       EDI,EDI
    //         004e9495     JZ         LAB_004e94db
    //         004e9497     MOV        this,dword ptr [ESI + 0x244]
    //         004e949d     XOR        EAX,EAX
    //         004e949f     TEST       this,this
    //         004e94a1     JLE        LAB_004e94c0
    //                               LAB_004e94a3                                                 XREF[1]:     004e94be(j)  
    //         004e94a3     CMP        EAX,EBP
    //         004e94a5     JGE        LAB_004e94c0
    //         004e94a7     MOV        this,dword ptr [ESI + 0x238]
    //         004e94ad     INC        EAX
    //         004e94ae     MOV        EDX,dword ptr [this->_padding_ + EAX*0x4 + -0x4]
    //         004e94b2     MOV        dword ptr [EDI + EAX*0x4 + -0x4],EDX
    //         004e94b6     MOV        this,dword ptr [ESI + 0x244]
    //         004e94bc     CMP        EAX,this
    //         004e94be     JL         LAB_004e94a3
    //                               LAB_004e94c0                                                 XREF[2]:     004e94a1(j), 004e94a5(j)  
    //         004e94c0     MOV        EAX,dword ptr [ESI + 0x238]
    //         004e94c6     PUSH       EAX
    //         004e94c7     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004e94cc     ADD        ESP,0x4
    //         004e94cf     MOV        dword ptr [ESI + 0x238],EDI
    //         004e94d5     MOV        dword ptr [ESI + 0x244],EBP
    //                               LAB_004e94db                                                 XREF[2]:     004e947c(j), 004e9495(j)  
    //         004e94db     MOV        this,dword ptr [ESI + 0x23c]
    //         004e94e1     MOV        EDX,dword ptr [ESI + 0x238]
    //         004e94e7     MOV        EAX,dword ptr [ESP + local_14]
    //         004e94eb     MOV        dword ptr [EDX + this->_padding_*0x4],EAX
    //         004e94ee     MOV        EAX,dword ptr [ESI + 0x23c]
    //         004e94f4     INC        EAX
    //         004e94f5     MOV        dword ptr [ESI + 0x23c],EAX
    //                               LAB_004e94fb                                                 XREF[1]:     004e9468(j)  
    //         004e94fb     MOV        EAX,dword ptr [ESP + tempIntNum]
    //         004e94ff     MOV        this,dword ptr [ESP + local_18]
    //         004e9503     INC        EAX
    //         004e9504     CMP        EAX,this
    //         004e9506     MOV        dword ptr [ESP + tempIntNum],EAX
    //         004e950a     JL         LAB_004e9430
    //                               LAB_004e9510                                                 XREF[1]:     004e942a(j)  
    //                              taistrmd.cpp:1233 (13)
    //         004e9510     LEA        this=>local_18,[ESP + 0x14]
    //         004e9514     PUSH       0x4
    //         004e9516     PUSH       this
    //         004e9517     PUSH       EBX
    //         004e9518     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              taistrmd.cpp:1234 (23)
    //         004e951d     MOV        EAX,dword ptr [ESP + local_18]
    //         004e9521     ADD        ESP,0xc
    //         004e9524     TEST       EAX,EAX
    //         004e9526     MOV        dword ptr [ESP + tempIntNum],0x0
    //         004e952e     JLE        LAB_004e9614
    //                               LAB_004e9534                                                 XREF[1]:     004e960e(j)  
    //                              taistrmd.cpp:1235 (13)
    //         004e9534     LEA        EDX=>param_1,[ESP + 0x30]
    //         004e9538     PUSH       0x4
    //         004e953a     PUSH       EDX
    //         004e953b     PUSH       EBX
    //         004e953c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              taistrmd.cpp:1236 (211)
    //         004e9541     MOV        this,dword ptr [ESI + 0x24c]
    //         004e9547     MOV        EDX,dword ptr [ESP + param_1]
    //         004e954b     ADD        ESP,0xc
    //         004e954e     XOR        EAX,EAX
    //         004e9550     TEST       this,this
    //         004e9552     MOV        dword ptr [ESP + local_14],EDX
    //         004e9556     JLE        LAB_004e9577
    //         004e9558     MOV        EDI,dword ptr [ESI + 0x254]
    //                               LAB_004e955e                                                 XREF[1]:     004e9575(j)  
    //         004e955e     CMP        EAX,EDI
    //         004e9560     JGE        LAB_004e9577
    //         004e9562     MOV        EBP,dword ptr [ESI + 0x248]
    //         004e9568     CMP        dword ptr [EBP + EAX*0x4],EDX
    //         004e956c     JZ         LAB_004e95ff
    //         004e9572     INC        EAX
    //         004e9573     CMP        EAX,this
    //         004e9575     JL         LAB_004e955e
    //                               LAB_004e9577                                                 XREF[2]:     004e9556(j), 004e9560(j)  
    //         004e9577     MOV        EAX,dword ptr [ESI + 0x254]
    //         004e957d     DEC        EAX
    //         004e957e     CMP        this,EAX
    //         004e9580     JLE        LAB_004e95df
    //         004e9582     LEA        EBP,[ECX + this+0x1]
    //         004e9585     LEA        this,[EBP*0x4 + 0x0]
    //         004e958c     PUSH       this
    //         004e958d     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004e9592     MOV        EDI,EAX
    //         004e9594     ADD        ESP,0x4
    //         004e9597     TEST       EDI,EDI
    //         004e9599     JZ         LAB_004e95df
    //         004e959b     MOV        this,dword ptr [ESI + 0x254]
    //         004e95a1     XOR        EAX,EAX
    //         004e95a3     TEST       this,this
    //         004e95a5     JLE        LAB_004e95c4
    //                               LAB_004e95a7                                                 XREF[1]:     004e95c2(j)  
    //         004e95a7     CMP        EAX,EBP
    //         004e95a9     JGE        LAB_004e95c4
    //         004e95ab     MOV        EDX,dword ptr [ESI + 0x248]
    //         004e95b1     INC        EAX
    //         004e95b2     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         004e95b6     MOV        dword ptr [EDI + EAX*0x4 + -0x4],this
    //         004e95ba     MOV        this,dword ptr [ESI + 0x254]
    //         004e95c0     CMP        EAX,this
    //         004e95c2     JL         LAB_004e95a7
    //                               LAB_004e95c4                                                 XREF[2]:     004e95a5(j), 004e95a9(j)  
    //         004e95c4     MOV        EDX,dword ptr [ESI + 0x248]
    //         004e95ca     PUSH       EDX
    //         004e95cb     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004e95d0     ADD        ESP,0x4
    //         004e95d3     MOV        dword ptr [ESI + 0x248],EDI
    //         004e95d9     MOV        dword ptr [ESI + 0x254],EBP
    //                               LAB_004e95df                                                 XREF[2]:     004e9580(j), 004e9599(j)  
    //         004e95df     MOV        EAX,dword ptr [ESI + 0x24c]
    //         004e95e5     MOV        this,dword ptr [ESI + 0x248]
    //         004e95eb     MOV        EDX,dword ptr [ESP + local_14]
    //         004e95ef     MOV        dword ptr [this->_padding_ + EAX*0x4],EDX
    //         004e95f2     MOV        EAX,dword ptr [ESI + 0x24c]
    //         004e95f8     INC        EAX
    //         004e95f9     MOV        dword ptr [ESI + 0x24c],EAX
    //                               LAB_004e95ff                                                 XREF[1]:     004e956c(j)  
    //         004e95ff     MOV        EAX,dword ptr [ESP + tempIntNum]
    //         004e9603     MOV        this,dword ptr [ESP + local_18]
    //         004e9607     INC        EAX
    //         004e9608     CMP        EAX,this
    //         004e960a     MOV        dword ptr [ESP + tempIntNum],EAX
    //         004e960e     JL         LAB_004e9534
    //                               LAB_004e9614                                                 XREF[1]:     004e952e(j)  
    //                              taistrmd.cpp:1238 (13)
    //         004e9614     LEA        EAX=>local_18,[ESP + 0x14]
    //         004e9618     PUSH       0x4
    //         004e961a     PUSH       EAX
    //         004e961b     PUSH       EBX
    //         004e961c     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              taistrmd.cpp:1239 (29)
    //         004e9621     MOV        EAX,dword ptr [ESP + local_18]
    //         004e9625     ADD        ESP,0xc
    //         004e9628     TEST       EAX,EAX
    //         004e962a     MOV        dword ptr [ESP + tempIntNum],0x0
    //         004e9632     JLE        LAB_004e9718
    //         004e9638     JMP        LAB_004e963e
    //                               LAB_004e963a                                                 XREF[1]:     004e9712(j)  
    //         004e963a     MOV        EBX,dword ptr [ESP + param_2]
    //                               LAB_004e963e                                                 XREF[1]:     004e9638(j)  
    //                              taistrmd.cpp:1240 (13)
    //         004e963e     LEA        this=>param_1,[ESP + 0x30]
    //         004e9642     PUSH       0x4
    //         004e9644     PUSH       this
    //         004e9645     PUSH       EBX
    //         004e9646     CALL       rge_read                                         void rge_read(int param_1, void * param_2, in
    //                              taistrmd.cpp:1241 (205)
    //         004e964b     MOV        this,dword ptr [ESI + 0x25c]
    //         004e9651     MOV        EDX,dword ptr [ESP + param_1]
    //         004e9655     ADD        ESP,0xc
    //         004e9658     XOR        EAX,EAX
    //         004e965a     TEST       this,this
    //         004e965c     MOV        EBX,EDX
    //         004e965e     JLE        LAB_004e967f
    //         004e9660     MOV        EDI,dword ptr [ESI + 0x264]
    //                               LAB_004e9666                                                 XREF[1]:     004e967d(j)  
    //         004e9666     CMP        EAX,EDI
    //         004e9668     JGE        LAB_004e967f
    //         004e966a     MOV        EBP,dword ptr [ESI + 0x258]
    //         004e9670     CMP        dword ptr [EBP + EAX*0x4],EDX
    //         004e9674     JZ         LAB_004e9703
    //         004e967a     INC        EAX
    //         004e967b     CMP        EAX,this
    //         004e967d     JL         LAB_004e9666
    //                               LAB_004e967f                                                 XREF[2]:     004e965e(j), 004e9668(j)  
    //         004e967f     MOV        EDX,dword ptr [ESI + 0x264]
    //         004e9685     DEC        EDX
    //         004e9686     CMP        this,EDX
    //         004e9688     JLE        LAB_004e96e7
    //         004e968a     LEA        EBP,[ECX + this+0x1]
    //         004e968d     LEA        EAX,[EBP*0x4 + 0x0]
    //         004e9694     PUSH       EAX
    //         004e9695     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004e969a     MOV        EDI,EAX
    //         004e969c     ADD        ESP,0x4
    //         004e969f     TEST       EDI,EDI
    //         004e96a1     JZ         LAB_004e96e7
    //         004e96a3     MOV        this,dword ptr [ESI + 0x264]
    //         004e96a9     XOR        EAX,EAX
    //         004e96ab     TEST       this,this
    //         004e96ad     JLE        LAB_004e96cc
    //                               LAB_004e96af                                                 XREF[1]:     004e96ca(j)  
    //         004e96af     CMP        EAX,EBP
    //         004e96b1     JGE        LAB_004e96cc
    //         004e96b3     MOV        this,dword ptr [ESI + 0x258]
    //         004e96b9     INC        EAX
    //         004e96ba     MOV        EDX,dword ptr [this->_padding_ + EAX*0x4 + -0x4]
    //         004e96be     MOV        dword ptr [EDI + EAX*0x4 + -0x4],EDX
    //         004e96c2     MOV        this,dword ptr [ESI + 0x264]
    //         004e96c8     CMP        EAX,this
    //         004e96ca     JL         LAB_004e96af
    //                               LAB_004e96cc                                                 XREF[2]:     004e96ad(j), 004e96b1(j)  
    //         004e96cc     MOV        EAX,dword ptr [ESI + 0x258]
    //         004e96d2     PUSH       EAX
    //         004e96d3     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004e96d8     ADD        ESP,0x4
    //         004e96db     MOV        dword ptr [ESI + 0x258],EDI
    //         004e96e1     MOV        dword ptr [ESI + 0x264],EBP
    //                               LAB_004e96e7                                                 XREF[2]:     004e9688(j), 004e96a1(j)  
    //         004e96e7     MOV        this,dword ptr [ESI + 0x25c]
    //         004e96ed     MOV        EDX,dword ptr [ESI + 0x258]
    //         004e96f3     MOV        dword ptr [EDX + this->_padding_*0x4],EBX
    //         004e96f6     MOV        EAX,dword ptr [ESI + 0x25c]
    //         004e96fc     INC        EAX
    //         004e96fd     MOV        dword ptr [ESI + 0x25c],EAX
    //                               LAB_004e9703                                                 XREF[1]:     004e9674(j)  
    //         004e9703     MOV        EAX,dword ptr [ESP + tempIntNum]
    //         004e9707     MOV        this,dword ptr [ESP + local_18]
    //         004e970b     INC        EAX
    //         004e970c     CMP        EAX,this
    //         004e970e     MOV        dword ptr [ESP + tempIntNum],EAX
    //         004e9712     JL         LAB_004e963a
    //                               LAB_004e9718                                                 XREF[1]:     004e9632(j)  
    //                              taistrmd.cpp:1243 (23)
    //         004e9718     MOV        this,dword ptr [ESP + local_c]
    //         004e971c     MOV        EAX,ESI
    //         004e971e     POP        EDI
    //         004e971f     POP        ESI
    //         004e9720     POP        EBP
    //         004e9721     MOV        dword ptr FS:[0x0],this
    //         004e9728     POP        EBX
    //         004e9729     ADD        ESP,0x1c
    //         004e972c     RET        0x8
}

// Offset: 0x004E9730
void TribeStrategyAIModule(TribeStrategyAIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual __thiscall TribeStrategyAIModule::~TribeStrategyAIModule(void)                        *
    //                              *********************************************************************************************************
    //                              void __thiscall ~TribeStrategyAIModule(TribeStrategyAIModule * this)
    //              void              <VOID>         <RETURN>
    //              TribeStrategyA    ECX:4 (auto)   this
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[5]:     004e975a(W), 004e9771(W), 004e97a1(W), 004e97d1(W), 
    //                                                                                     004e97fa(W)  
    //              undefined4        Stack[-0xc]:4  local_c                   XREF[1]:     004e9807(R)  
    //              undefined4        Stack[-0x10]:4 local_10                  XREF[1]:     004e974a(W)  
    //                               ??1TribeStrategyAIModule@@UAE@XZ                             XREF[4]:     ~TribeMainDecisionAIModule:004e4f1
    //                               TribeStrategyAIModule::~TribeStrategyAIModule                             `vector_deleting_destructor':004e9
    //                                                                                                         FUN_0056067c:00560685(c), 
    //                                                                                                         FUN_0056070c:00560715(c)  
    //                              taistrmd.cpp:1248 (55)
    //         004e9730     PUSH       -0x1
    //         004e9732     PUSH       FUN_00560842
    //         004e9737     MOV        EAX,FS:[0x0]
    //         004e973d     PUSH       EAX
    //         004e973e     MOV        dword ptr FS:[0x0],ESP
    //         004e9745     PUSH       this
    //         004e9746     PUSH       EBX
    //         004e9747     PUSH       ESI
    //         004e9748     MOV        ESI,this
    //         004e974a     MOV        dword ptr [ESP + local_10],ESI
    //         004e974e     MOV        dword ptr [ESI],TribeStrategyAIModule::`vftable' = 004e9240
    //         004e9754     LEA        this,[ESI + 0x268]
    //         004e975a     MOV        dword ptr [ESP + local_4],0x3
    //         004e9762     CALL       VictoryConditionRuleSystem::~VictoryConditionR   void ~VictoryConditionRuleSystem(VictoryCondi
    //                              taistrmd.cpp:1249 (177)
    //         004e9767     MOV        EAX,dword ptr [ESI + 0x258]
    //         004e976d     XOR        EBX,EBX
    //         004e976f     CMP        EAX,EBX
    //         004e9771     MOV        byte ptr [ESP + local_4],0x2
    //         004e9776     JZ         LAB_004e9787
    //         004e9778     PUSH       EAX
    //         004e9779     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004e977e     ADD        ESP,0x4
    //         004e9781     MOV        dword ptr [ESI + 0x258],EBX
    //                               LAB_004e9787                                                 XREF[1]:     004e9776(j)  
    //         004e9787     MOV        dword ptr [ESI + 0x25c],EBX
    //         004e978d     MOV        dword ptr [ESI + 0x260],EBX
    //         004e9793     MOV        dword ptr [ESI + 0x264],EBX
    //         004e9799     MOV        EAX,dword ptr [ESI + 0x248]
    //         004e979f     CMP        EAX,EBX
    //         004e97a1     MOV        byte ptr [ESP + local_4],0x1
    //         004e97a6     JZ         LAB_004e97b7
    //         004e97a8     PUSH       EAX
    //         004e97a9     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004e97ae     ADD        ESP,0x4
    //         004e97b1     MOV        dword ptr [ESI + 0x248],EBX
    //                               LAB_004e97b7                                                 XREF[1]:     004e97a6(j)  
    //         004e97b7     MOV        dword ptr [ESI + 0x24c],EBX
    //         004e97bd     MOV        dword ptr [ESI + 0x250],EBX
    //         004e97c3     MOV        dword ptr [ESI + 0x254],EBX
    //         004e97c9     MOV        EAX,dword ptr [ESI + 0x238]
    //         004e97cf     CMP        EAX,EBX
    //         004e97d1     MOV        byte ptr [ESP + local_4],BL
    //         004e97d5     JZ         LAB_004e97e6
    //         004e97d7     PUSH       EAX
    //         004e97d8     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004e97dd     ADD        ESP,0x4
    //         004e97e0     MOV        dword ptr [ESI + 0x238],EBX
    //                               LAB_004e97e6                                                 XREF[1]:     004e97d5(j)  
    //         004e97e6     MOV        this,ESI
    //         004e97e8     MOV        dword ptr [ESI + 0x23c],EBX
    //         004e97ee     MOV        dword ptr [ESI + 0x240],EBX
    //         004e97f4     MOV        dword ptr [ESI + 0x244],EBX
    //         004e97fa     MOV        dword ptr [ESP + local_4],0xffffffff
    //         004e9802     CALL       StrategyAIModule::~StrategyAIModule              void ~StrategyAIModule(StrategyAIModule * this)
    //         004e9807     MOV        this,dword ptr [ESP + local_c]
    //         004e980b     POP        ESI
    //         004e980c     MOV        dword ptr FS:[0x0],this
    //         004e9813     POP        EBX
    //         004e9814     ADD        ESP,0x10
    //         004e9817     RET
}

// Offset: 0x004E9820
int TribeStrategyAIModule::update(int param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall TribeStrategyAIModule::update(int)                                     *
    //                              *********************************************************************************************************
    //                              int __thiscall update(TribeStrategyAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              TribeStrategyA    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1
    //              undefined4        Stack[-0x4]:4  local_4                   XREF[5]:     004e9956(W), 004e99b1(R), 004e9aab(W), 004e9b5c(W), 
    //                                                                                     004e9b6f(R)  
    //              int               Stack[-0x8]:4  result                    XREF[6]:     004e9913(W), 004e99b8(W), 004e99cb(R), 004e9ab1(W), 
    //                                                                                     004e9b38(R), 004e9b55(W)  
    //              int               Stack[-0xc]:4  worstRuleResult
    //                               ?update@TribeStrategyAIModule@@UAEHH@Z                       XREF[1]:     005756c8(*)  
    //                               TribeStrategyAIModule::update
    //                              taistrmd.cpp:1254 (9)
    //         004e9820     SUB        ESP,0x8
    //         004e9823     PUSH       EBX
    //         004e9824     PUSH       EBP
    //         004e9825     PUSH       ESI
    //         004e9826     MOV        ESI,this
    //         004e9828     PUSH       EDI
    //                              taistrmd.cpp:1263 (24)
    //         004e9829     MOV        EBP,0x0
    //         004e982e     MOV        EAX,dword ptr [ESI + 0x234]
    //         004e9834     INC        EAX
    //         004e9835     MOV        dword ptr [ESI + 0x234],EAX
    //         004e983b     JS         LAB_004e9906
    //                              taistrmd.cpp:1274 (32)
    //         004e9841     MOV        EAX,dword ptr [ESI + 0xf0]
    //         004e9847     MOV        dword ptr [ESI + 0x234],EBP
    //         004e984d     PUSH       EBP
    //         004e984e     MOV        EDI,0xb
    //         004e9853     MOV        this,dword ptr [EAX + 0xf0]
    //         004e9859     MOV        this,dword ptr [ECX + this->_padding_]
    //         004e985c     CALL       RGE_Victory_Conditions::condition_raw_info       RGE_Victory_Entry * condition_raw_info(RGE_Vi
    //                              taistrmd.cpp:1275 (8)
    //         004e9861     CMP        EAX,EBP
    //         004e9863     JZ         LAB_004e98f6
    //                              taistrmd.cpp:1278 (13)
    //         004e9869     MOV        this,dword ptr [EAX + 0x28]
    //         004e986c     XOR        EDX,EDX
    //         004e986e     MOV        DL,byte ptr [EAX]
    //         004e9870     CMP        this,EBP
    //         004e9872     MOV        EDI,EDX
    //         004e9874     JZ         LAB_004e988f
    //                              taistrmd.cpp:1279 (9)
    //         004e9876     MOV        this,dword ptr [ECX + this->_padding_]
    //         004e9879     MOV        dword ptr [ESI + 0x1fc],this
    //                              taistrmd.cpp:1280 (16)
    //         004e987f     MOV        EDX,dword ptr [EAX + 0x28]
    //         004e9882     MOV        this,dword ptr [EDX + 0x8]
    //         004e9885     MOVSX      EDX,word ptr [ECX + this->_padding_]
    //         004e9889     MOV        dword ptr [ESI + 0x200],EDX
    //                               LAB_004e988f                                                 XREF[1]:     004e9874(j)  
    //                              taistrmd.cpp:1282 (7)
    //         004e988f     MOV        this,dword ptr [EAX + 0x24]
    //         004e9892     CMP        this,EBP
    //         004e9894     JZ         LAB_004e98af
    //                              taistrmd.cpp:1283 (9)
    //         004e9896     MOV        this,dword ptr [ECX + this->_padding_]
    //         004e9899     MOV        dword ptr [ESI + 0x204],this
    //                              taistrmd.cpp:1284 (16)
    //         004e989f     MOV        EDX,dword ptr [EAX + 0x24]
    //         004e98a2     MOV        this,dword ptr [EDX + 0x8]
    //         004e98a5     MOVSX      EDX,word ptr [ECX + this->_padding_]
    //         004e98a9     MOV        dword ptr [ESI + 0x208],EDX
    //                               LAB_004e98af                                                 XREF[1]:     004e9894(j)  
    //                              taistrmd.cpp:1286 (9)
    //         004e98af     MOV        this,dword ptr [EAX + 0xc]
    //         004e98b2     MOV        dword ptr [ESI + 0x20c],this
    //                              taistrmd.cpp:1287 (3)
    //         004e98b8     MOV        EDX,dword ptr [EAX + 0x10]
    //                              taistrmd.cpp:1288 (17)
    //         004e98bb     MOV        this,0x3f800000
    //         004e98c0     MOV        dword ptr [ESI + 0x210],EDX
    //         004e98c6     MOV        dword ptr [ESI + 0x214],this
    //                              taistrmd.cpp:1289 (9)
    //         004e98cc     MOV        EDX,dword ptr [EAX + 0x14]
    //         004e98cf     MOV        dword ptr [ESI + 0x21c],EDX
    //                              taistrmd.cpp:1290 (9)
    //         004e98d5     MOV        EDX,dword ptr [EAX + 0x18]
    //         004e98d8     MOV        dword ptr [ESI + 0x220],EDX
    //                              taistrmd.cpp:1291 (6)
    //         004e98de     MOV        dword ptr [ESI + 0x224],this
    //                              taistrmd.cpp:1292 (9)
    //         004e98e4     MOV        this,dword ptr [EAX + 0x1c]
    //         004e98e7     MOV        dword ptr [ESI + 0x22c],this
    //                              taistrmd.cpp:1293 (9)
    //         004e98ed     MOV        EDX,dword ptr [EAX + 0x20]
    //         004e98f0     MOV        dword ptr [ESI + 0x230],EDX
    //                               LAB_004e98f6                                                 XREF[1]:     004e9863(j)  
    //                              taistrmd.cpp:1297 (8)
    //         004e98f6     CMP        EDI,dword ptr [ESI + 0xf4]
    //         004e98fc     JZ         LAB_004e9906
    //                              taistrmd.cpp:1298 (8)
    //         004e98fe     PUSH       EDI
    //         004e98ff     MOV        this,ESI
    //         004e9901     CALL       TribeStrategyAIModule::setVictoryCondition       void setVictoryCondition(TribeStrategyAIModul
    //                               LAB_004e9906                                                 XREF[2]:     004e983b(j), 004e98fc(j)  
    //                              taistrmd.cpp:1305 (23)
    //         004e9906     MOV        EAX,dword ptr [ESI + 0x25c]
    //         004e990c     OR         EDI,0xffffffff
    //         004e990f     XOR        EBX,EBX
    //         004e9911     CMP        EAX,EBP
    //         004e9913     MOV        dword ptr [ESP + result],EDI
    //         004e9917     JLE        LAB_004e99cf
    //                              taistrmd.cpp:1307 (55)
    //         004e991d     LEA        EDI,[ESI + 0x258]
    //                               LAB_004e9923                                                 XREF[1]:     004e99c5(j)  
    //         004e9923     MOV        EAX,dword ptr [EDI + 0xc]
    //         004e9926     DEC        EAX
    //         004e9927     CMP        EBP,EAX
    //         004e9929     JLE        LAB_004e9936
    //         004e992b     LEA        this,[EBP + 0x1]
    //         004e992e     PUSH       this
    //         004e992f     MOV        this,EDI
    //         004e9931     CALL       ManagedArray<int>::resize                        int resize(ManagedArray<int> * this, int para
    //                               LAB_004e9936                                                 XREF[1]:     004e9929(j)  
    //         004e9936     MOV        EDX,dword ptr [EDI]
    //         004e9938     MOV        this,dword ptr [ESI + 0xf0]
    //         004e993e     MOV        EAX,dword ptr [EDX + EBP*0x4]
    //         004e9941     MOV        EDX,dword ptr [this->_padding_ + 0x1256c]
    //         004e9947     PUSH       EAX
    //         004e9948     PUSH       EDX
    //         004e9949     LEA        this,[ESI + 0x268]
    //         004e994f     CALL       VictoryConditionRuleSystem::evaluateAsNonInPro   int evaluateAsNonInProgress(VictoryConditionR
    //                              taistrmd.cpp:1308 (8)
    //         004e9954     CMP        EAX,EBX
    //         004e9956     MOV        dword ptr [ESP + local_4],EAX
    //         004e995a     JLE        LAB_004e99bc
    //                              taistrmd.cpp:1309 (85)
    //         004e995c     MOV        EAX,dword ptr [EDI + 0xc]
    //         004e995f     DEC        EAX
    //         004e9960     CMP        EBP,EAX
    //         004e9962     JLE        LAB_004e99af
    //         004e9964     LEA        this,[EBP*0x4 + 0x4]
    //         004e996b     PUSH       this
    //         004e996c     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004e9971     MOV        EBX,EAX
    //         004e9973     ADD        ESP,0x4
    //         004e9976     TEST       EBX,EBX
    //         004e9978     JZ         LAB_004e99af
    //         004e997a     MOV        this,dword ptr [EDI + 0xc]
    //         004e997d     XOR        EAX,EAX
    //         004e997f     TEST       this,this
    //         004e9981     JLE        LAB_004e999c
    //                               LAB_004e9983                                                 XREF[1]:     004e999a(j)  
    //         004e9983     LEA        this,[EBP + 0x1]
    //         004e9986     CMP        EAX,this
    //         004e9988     JGE        LAB_004e999c
    //         004e998a     MOV        EDX,dword ptr [EDI]
    //         004e998c     INC        EAX
    //         004e998d     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         004e9991     MOV        dword ptr [EBX + EAX*0x4 + -0x4],this
    //         004e9995     MOV        this,dword ptr [EDI + 0xc]
    //         004e9998     CMP        EAX,this
    //         004e999a     JL         LAB_004e9983
    //                               LAB_004e999c                                                 XREF[2]:     004e9981(j), 004e9988(j)  
    //         004e999c     MOV        EDX,dword ptr [EDI]
    //         004e999e     PUSH       EDX
    //         004e999f     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004e99a4     LEA        EAX,[EBP + 0x1]
    //         004e99a7     ADD        ESP,0x4
    //         004e99aa     MOV        dword ptr [EDI],EBX
    //         004e99ac     MOV        dword ptr [EDI + 0xc],EAX
    //                               LAB_004e99af                                                 XREF[2]:     004e9962(j), 004e9978(j)  
    //         004e99af     MOV        EAX,dword ptr [EDI]
    //                              taistrmd.cpp:1310 (26)
    //         004e99b1     MOV        EBX,dword ptr [ESP + local_4]
    //         004e99b5     MOV        this,dword ptr [EAX + EBP*0x4]
    //         004e99b8     MOV        dword ptr [ESP + result],this
    //                               LAB_004e99bc                                                 XREF[1]:     004e995a(j)  
    //         004e99bc     MOV        EAX,dword ptr [ESI + 0x25c]
    //         004e99c2     INC        EBP
    //         004e99c3     CMP        EBP,EAX
    //         004e99c5     JL         LAB_004e9923
    //                              taistrmd.cpp:1305 (4)
    //         004e99cb     MOV        EDI,dword ptr [ESP + result]
    //                               LAB_004e99cf                                                 XREF[1]:     004e9917(j)  
    //                              taistrmd.cpp:1313 (9)
    //         004e99cf     CMP        EDI,-0x1
    //         004e99d2     JZ         LAB_004e9aa0
    //                              taistrmd.cpp:1315 (32)
    //         004e99d8     MOV        EAX,dword ptr [ESI + 0xf0]
    //         004e99de     MOV        EDX,dword ptr [ESI + 0xf4]
    //         004e99e4     PUSH       EDI
    //         004e99e5     PUSH       EDX
    //         004e99e6     MOV        this,dword ptr [EAX + 0x1256c]
    //         004e99ec     PUSH       this
    //         004e99ed     LEA        this,[ESI + 0x268]
    //         004e99f3     CALL       VictoryConditionRuleSystem::execute              int execute(VictoryConditionRuleSystem * this
    //                              taistrmd.cpp:1316 (9)
    //         004e99f8     CMP        EAX,0x1
    //         004e99fb     JNZ        LAB_004e9aa0
    //                              taistrmd.cpp:1317 (70)
    //         004e9a01     MOV        this,dword ptr [ESI + 0x24c]
    //         004e9a07     LEA        EBX,[ESI + 0x248]
    //         004e9a0d     XOR        EAX,EAX
    //         004e9a0f     TEST       this,this
    //         004e9a11     JLE        LAB_004e9a27
    //         004e9a13     MOV        EDX,dword ptr [EBX + 0xc]
    //                               LAB_004e9a16                                                 XREF[1]:     004e9a25(j)  
    //         004e9a16     CMP        EAX,EDX
    //         004e9a18     JGE        LAB_004e9a27
    //         004e9a1a     MOV        EBP,dword ptr [EBX]
    //         004e9a1c     CMP        dword ptr [EBP + EAX*0x4],EDI
    //         004e9a20     JZ         LAB_004e9a47
    //         004e9a22     INC        EAX
    //         004e9a23     CMP        EAX,this
    //         004e9a25     JL         LAB_004e9a16
    //                               LAB_004e9a27                                                 XREF[2]:     004e9a11(j), 004e9a18(j)  
    //         004e9a27     MOV        EDX,dword ptr [EBX + 0xc]
    //         004e9a2a     DEC        EDX
    //         004e9a2b     CMP        this,EDX
    //         004e9a2d     JLE        LAB_004e9a38
    //         004e9a2f     INC        this
    //         004e9a30     PUSH       this
    //         004e9a31     MOV        this,EBX
    //         004e9a33     CALL       ManagedArray<int>::resize                        int resize(ManagedArray<int> * this, int para
    //                               LAB_004e9a38                                                 XREF[1]:     004e9a2d(j)  
    //         004e9a38     MOV        EAX,dword ptr [EBX + 0x4]
    //         004e9a3b     MOV        this,dword ptr [EBX]
    //         004e9a3d     MOV        dword ptr [this->_padding_ + EAX*0x4],EDI
    //         004e9a40     MOV        EAX,dword ptr [EBX + 0x4]
    //         004e9a43     INC        EAX
    //         004e9a44     MOV        dword ptr [EBX + 0x4],EAX
    //                               LAB_004e9a47                                                 XREF[1]:     004e9a20(j)  
    //                              taistrmd.cpp:1318 (89)
    //         004e9a47     MOV        EDX,dword ptr [ESI + 0x264]
    //         004e9a4d     XOR        EAX,EAX
    //         004e9a4f     TEST       EDX,EDX
    //         004e9a51     JLE        LAB_004e9a65
    //         004e9a53     MOV        this,dword ptr [ESI + 0x258]
    //                               LAB_004e9a59                                                 XREF[1]:     004e9a63(j)  
    //         004e9a59     CMP        dword ptr [this->_padding_],EDI
    //         004e9a5b     JZ         LAB_004e9a65
    //         004e9a5d     INC        EAX
    //         004e9a5e     ADD        this,0x4
    //         004e9a61     CMP        EAX,EDX
    //         004e9a63     JL         LAB_004e9a59
    //                               LAB_004e9a65                                                 XREF[2]:     004e9a51(j), 004e9a5b(j)  
    //         004e9a65     CMP        EAX,EDX
    //         004e9a67     JGE        LAB_004e9aa0
    //         004e9a69     DEC        EDX
    //         004e9a6a     CMP        EAX,EDX
    //         004e9a6c     JGE        LAB_004e9a87
    //                               LAB_004e9a6e                                                 XREF[1]:     004e9a85(j)  
    //         004e9a6e     MOV        this,dword ptr [ESI + 0x258]
    //         004e9a74     INC        EAX
    //         004e9a75     MOV        EDX,dword ptr [this->_padding_ + EAX*0x4]
    //         004e9a78     MOV        dword ptr [this->_padding_ + EAX*0x4 + -0x4],EDX
    //         004e9a7c     MOV        this,dword ptr [ESI + 0x264]
    //         004e9a82     DEC        this
    //         004e9a83     CMP        EAX,this
    //         004e9a85     JL         LAB_004e9a6e
    //                               LAB_004e9a87                                                 XREF[1]:     004e9a6c(j)  
    //         004e9a87     MOV        EAX,dword ptr [ESI + 0x25c]
    //         004e9a8d     DEC        EAX
    //         004e9a8e     MOV        dword ptr [ESI + 0x25c],EAX
    //         004e9a94     JNS        LAB_004e9aa0
    //         004e9a96     MOV        dword ptr [ESI + 0x25c],0x0
    //                               LAB_004e9aa0                                                 XREF[4]:     004e99d2(j), 004e99fb(j), 
    //                                                                                                         004e9a67(j), 004e9a94(j)  
    //                              taistrmd.cpp:1325 (31)
    //         004e9aa0     MOV        EAX,dword ptr [ESI + 0x24c]
    //         004e9aa6     OR         EBX,0xffffffff
    //         004e9aa9     XOR        EBP,EBP
    //         004e9aab     MOV        dword ptr [ESP + local_4],EBX
    //         004e9aaf     TEST       EAX,EAX
    //                              language.dll match for 0x65: "1"
    //         004e9ab1     MOV        dword ptr [ESP + result],0x65
    //         004e9ab9     JLE        LAB_004e9b73
    //                              taistrmd.cpp:1327 (121)
    //         004e9abf     LEA        EDI,[ESI + 0x248]
    //                               LAB_004e9ac5                                                 XREF[1]:     004e9b69(j)  
    //         004e9ac5     MOV        EDX,dword ptr [EDI + 0xc]
    //         004e9ac8     DEC        EDX
    //         004e9ac9     CMP        EBP,EDX
    //         004e9acb     JLE        LAB_004e9b18
    //         004e9acd     LEA        EAX,[EBP*0x4 + 0x4]
    //         004e9ad4     PUSH       EAX
    //         004e9ad5     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004e9ada     MOV        EBX,EAX
    //         004e9adc     ADD        ESP,0x4
    //         004e9adf     TEST       EBX,EBX
    //         004e9ae1     JZ         LAB_004e9b18
    //         004e9ae3     MOV        this,dword ptr [EDI + 0xc]
    //         004e9ae6     XOR        EAX,EAX
    //         004e9ae8     TEST       this,this
    //         004e9aea     JLE        LAB_004e9b05
    //                               LAB_004e9aec                                                 XREF[1]:     004e9b03(j)  
    //         004e9aec     LEA        this,[EBP + 0x1]
    //         004e9aef     CMP        EAX,this
    //         004e9af1     JGE        LAB_004e9b05
    //         004e9af3     MOV        this,dword ptr [EDI]
    //         004e9af5     INC        EAX
    //         004e9af6     MOV        EDX,dword ptr [this->_padding_ + EAX*0x4 + -0x4]
    //         004e9afa     MOV        dword ptr [EBX + EAX*0x4 + -0x4],EDX
    //         004e9afe     MOV        this,dword ptr [EDI + 0xc]
    //         004e9b01     CMP        EAX,this
    //         004e9b03     JL         LAB_004e9aec
    //                               LAB_004e9b05                                                 XREF[2]:     004e9aea(j), 004e9af1(j)  
    //         004e9b05     MOV        EAX,dword ptr [EDI]
    //         004e9b07     PUSH       EAX
    //         004e9b08     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004e9b0d     LEA        EAX,[EBP + 0x1]
    //         004e9b10     ADD        ESP,0x4
    //         004e9b13     MOV        dword ptr [EDI],EBX
    //         004e9b15     MOV        dword ptr [EDI + 0xc],EAX
    //                               LAB_004e9b18                                                 XREF[2]:     004e9acb(j), 004e9ae1(j)  
    //         004e9b18     MOV        this,dword ptr [EDI]
    //         004e9b1a     MOV        EAX,dword ptr [ESI + 0xf0]
    //         004e9b20     MOV        EDX,dword ptr [this->_padding_ + EBP*0x4]
    //         004e9b23     MOV        this,dword ptr [EAX + 0x1256c]
    //         004e9b29     PUSH       EDX
    //         004e9b2a     PUSH       this
    //         004e9b2b     LEA        this,[ESI + 0x268]
    //         004e9b31     CALL       VictoryConditionRuleSystem::evaluateAsInProgress int evaluateAsInProgress(VictoryConditionRule
    //         004e9b36     MOV        EBX,EAX
    //                              taistrmd.cpp:1328 (8)
    //         004e9b38     MOV        EAX,dword ptr [ESP + result]
    //         004e9b3c     CMP        EBX,EAX
    //         004e9b3e     JGE        LAB_004e9b60
    //                              taistrmd.cpp:1329 (21)
    //         004e9b40     MOV        EDX,dword ptr [EDI + 0xc]
    //         004e9b43     DEC        EDX
    //         004e9b44     CMP        EBP,EDX
    //         004e9b46     JLE        LAB_004e9b53
    //         004e9b48     LEA        EAX,[EBP + 0x1]
    //         004e9b4b     MOV        this,EDI
    //         004e9b4d     PUSH       EAX
    //         004e9b4e     CALL       ManagedArray<int>::resize                        int resize(ManagedArray<int> * this, int para
    //                               LAB_004e9b53                                                 XREF[1]:     004e9b46(j)  
    //         004e9b53     MOV        this,dword ptr [EDI]
    //                              taistrmd.cpp:1330 (26)
    //         004e9b55     MOV        dword ptr [ESP + result],EBX
    //         004e9b59     MOV        EDX,dword ptr [this->_padding_ + EBP*0x4]
    //         004e9b5c     MOV        dword ptr [ESP + local_4],EDX
    //                               LAB_004e9b60                                                 XREF[1]:     004e9b3e(j)  
    //         004e9b60     MOV        EAX,dword ptr [ESI + 0x24c]
    //         004e9b66     INC        EBP
    //         004e9b67     CMP        EBP,EAX
    //         004e9b69     JL         LAB_004e9ac5
    //                              taistrmd.cpp:1325 (4)
    //         004e9b6f     MOV        EBX,dword ptr [ESP + local_4]
    //                               LAB_004e9b73                                                 XREF[1]:     004e9ab9(j)  
    //                              taistrmd.cpp:1333 (9)
    //         004e9b73     CMP        EBX,-0x1
    //         004e9b76     JZ         LAB_004e9c3d
    //                              taistrmd.cpp:1334 (25)
    //         004e9b7c     MOV        EAX,dword ptr [ESI + 0xf0]
    //         004e9b82     PUSH       EBX
    //         004e9b83     MOV        this,dword ptr [EAX + 0x1256c]
    //         004e9b89     PUSH       this
    //         004e9b8a     LEA        this,[ESI + 0x268]
    //         004e9b90     CALL       VictoryConditionRuleSystem::stopExecution        int stopExecution(VictoryConditionRuleSystem 
    //                              taistrmd.cpp:1335 (9)
    //         004e9b95     CMP        EAX,0x1
    //         004e9b98     JNZ        LAB_004e9c3d
    //                              taistrmd.cpp:1336 (12)
    //         004e9b9e     MOV        EDX,dword ptr [ESI + 0x254]
    //         004e9ba4     XOR        EAX,EAX
    //         004e9ba6     TEST       EDX,EDX
    //         004e9ba8     JLE        LAB_004e9bbc
    //                              taistrmd.cpp:1352 (6)
    //         004e9baa     MOV        this,dword ptr [ESI + 0x248]
    //                               LAB_004e9bb0                                                 XREF[1]:     004e9bba(j)  
    //                              taistrmd.cpp:1336 (71)
    //         004e9bb0     CMP        dword ptr [this->_padding_],EBX
    //         004e9bb2     JZ         LAB_004e9bbc
    //         004e9bb4     INC        EAX
    //         004e9bb5     ADD        this,0x4
    //         004e9bb8     CMP        EAX,EDX
    //         004e9bba     JL         LAB_004e9bb0
    //                               LAB_004e9bbc                                                 XREF[2]:     004e9ba8(j), 004e9bb2(j)  
    //         004e9bbc     CMP        EAX,EDX
    //         004e9bbe     JGE        LAB_004e9bf7
    //         004e9bc0     DEC        EDX
    //         004e9bc1     CMP        EAX,EDX
    //         004e9bc3     JGE        LAB_004e9bde
    //                               LAB_004e9bc5                                                 XREF[1]:     004e9bdc(j)  
    //         004e9bc5     MOV        this,dword ptr [ESI + 0x248]
    //         004e9bcb     INC        EAX
    //         004e9bcc     MOV        EDX,dword ptr [this->_padding_ + EAX*0x4]
    //         004e9bcf     MOV        dword ptr [this->_padding_ + EAX*0x4 + -0x4],EDX
    //         004e9bd3     MOV        this,dword ptr [ESI + 0x254]
    //         004e9bd9     DEC        this
    //         004e9bda     CMP        EAX,this
    //         004e9bdc     JL         LAB_004e9bc5
    //                               LAB_004e9bde                                                 XREF[1]:     004e9bc3(j)  
    //         004e9bde     MOV        EAX,dword ptr [ESI + 0x24c]
    //         004e9be4     DEC        EAX
    //         004e9be5     MOV        dword ptr [ESI + 0x24c],EAX
    //         004e9beb     JNS        LAB_004e9bf7
    //         004e9bed     MOV        dword ptr [ESI + 0x24c],0x0
    //                               LAB_004e9bf7                                                 XREF[2]:     004e9bbe(j), 004e9beb(j)  
    //                              taistrmd.cpp:1337 (70)
    //         004e9bf7     MOV        this,dword ptr [ESI + 0x25c]
    //         004e9bfd     LEA        EDI,[ESI + 0x258]
    //         004e9c03     XOR        EAX,EAX
    //         004e9c05     TEST       this,this
    //         004e9c07     JLE        LAB_004e9c1d
    //         004e9c09     MOV        EDX,dword ptr [EDI + 0xc]
    //                               LAB_004e9c0c                                                 XREF[1]:     004e9c1b(j)  
    //         004e9c0c     CMP        EAX,EDX
    //         004e9c0e     JGE        LAB_004e9c1d
    //         004e9c10     MOV        EBP,dword ptr [EDI]
    //         004e9c12     CMP        dword ptr [EBP + EAX*0x4],EBX
    //         004e9c16     JZ         LAB_004e9c3d
    //         004e9c18     INC        EAX
    //         004e9c19     CMP        EAX,this
    //         004e9c1b     JL         LAB_004e9c0c
    //                               LAB_004e9c1d                                                 XREF[2]:     004e9c07(j), 004e9c0e(j)  
    //         004e9c1d     MOV        EDX,dword ptr [EDI + 0xc]
    //         004e9c20     DEC        EDX
    //         004e9c21     CMP        this,EDX
    //         004e9c23     JLE        LAB_004e9c2e
    //         004e9c25     INC        this
    //         004e9c26     PUSH       this
    //         004e9c27     MOV        this,EDI
    //         004e9c29     CALL       ManagedArray<int>::resize                        int resize(ManagedArray<int> * this, int para
    //                               LAB_004e9c2e                                                 XREF[1]:     004e9c23(j)  
    //         004e9c2e     MOV        EAX,dword ptr [EDI + 0x4]
    //         004e9c31     MOV        this,dword ptr [EDI]
    //         004e9c33     MOV        dword ptr [this->_padding_ + EAX*0x4],EBX
    //         004e9c36     MOV        EAX,dword ptr [EDI + 0x4]
    //         004e9c39     INC        EAX
    //         004e9c3a     MOV        dword ptr [EDI + 0x4],EAX
    //                               LAB_004e9c3d                                                 XREF[3]:     004e9b76(j), 004e9b98(j), 
    //                                                                                                         004e9c16(j)  
    //                              taistrmd.cpp:1343 (16)
    //         004e9c3d     MOV        EAX,dword ptr [ESI + 0x23c]
    //         004e9c43     XOR        EBX,EBX
    //         004e9c45     TEST       EAX,EAX
    //         004e9c47     JLE        LAB_004e9d80
    //                               LAB_004e9c4d                                                 XREF[1]:     004e9d7a(j)  
    //                              taistrmd.cpp:1345 (147)
    //         004e9c4d     MOV        EDX,dword ptr [ESI + 0x244]
    //         004e9c53     DEC        EDX
    //         004e9c54     CMP        EBX,EDX
    //         004e9c56     JLE        LAB_004e9cb5
    //         004e9c58     LEA        EAX,[EBX*0x4 + 0x4]
    //         004e9c5f     LEA        EBP,[EBX + 0x1]
    //         004e9c62     PUSH       EAX
    //         004e9c63     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004e9c68     MOV        EDI,EAX
    //         004e9c6a     ADD        ESP,0x4
    //         004e9c6d     TEST       EDI,EDI
    //         004e9c6f     JZ         LAB_004e9cb5
    //         004e9c71     MOV        this,dword ptr [ESI + 0x244]
    //         004e9c77     XOR        EAX,EAX
    //         004e9c79     TEST       this,this
    //         004e9c7b     JLE        LAB_004e9c9a
    //                               LAB_004e9c7d                                                 XREF[1]:     004e9c98(j)  
    //         004e9c7d     CMP        EAX,EBP
    //         004e9c7f     JGE        LAB_004e9c9a
    //         004e9c81     MOV        this,dword ptr [ESI + 0x238]
    //         004e9c87     INC        EAX
    //         004e9c88     MOV        EDX,dword ptr [this->_padding_ + EAX*0x4 + -0x4]
    //         004e9c8c     MOV        dword ptr [EDI + EAX*0x4 + -0x4],EDX
    //         004e9c90     MOV        this,dword ptr [ESI + 0x244]
    //         004e9c96     CMP        EAX,this
    //         004e9c98     JL         LAB_004e9c7d
    //                               LAB_004e9c9a                                                 XREF[2]:     004e9c7b(j), 004e9c7f(j)  
    //         004e9c9a     MOV        EAX,dword ptr [ESI + 0x238]
    //         004e9ca0     PUSH       EAX
    //         004e9ca1     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004e9ca6     ADD        ESP,0x4
    //         004e9ca9     MOV        dword ptr [ESI + 0x238],EDI
    //         004e9caf     MOV        dword ptr [ESI + 0x244],EBP
    //                               LAB_004e9cb5                                                 XREF[2]:     004e9c56(j), 004e9c6f(j)  
    //         004e9cb5     MOV        EDX,dword ptr [ESI + 0x238]
    //         004e9cbb     LEA        this,[ESI + 0x268]
    //         004e9cc1     MOV        EAX,dword ptr [EDX + EBX*0x4]
    //         004e9cc4     MOV        EDX,dword ptr [ESI + 0xf0]
    //         004e9cca     PUSH       EAX
    //         004e9ccb     MOV        EAX,dword ptr [EDX + 0x1256c]
    //         004e9cd1     PUSH       EAX
    //         004e9cd2     CALL       VictoryConditionRuleSystem::evaluateAsNonInPro   int evaluateAsNonInProgress(VictoryConditionR
    //         004e9cd7     CMP        EAX,-0x1
    //         004e9cda     JNZ        LAB_004e9d71
    //                              taistrmd.cpp:1347 (160)
    //         004e9ce0     MOV        this,dword ptr [ESI + 0x244]
    //         004e9ce6     DEC        this
    //         004e9ce7     CMP        EBX,this
    //         004e9ce9     JLE        LAB_004e9d48
    //         004e9ceb     LEA        EDX,[EBX*0x4 + 0x4]
    //         004e9cf2     LEA        EBP,[EBX + 0x1]
    //         004e9cf5     PUSH       EDX
    //         004e9cf6     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004e9cfb     MOV        EDI,EAX
    //         004e9cfd     ADD        ESP,0x4
    //         004e9d00     TEST       EDI,EDI
    //         004e9d02     JZ         LAB_004e9d48
    //         004e9d04     MOV        this,dword ptr [ESI + 0x244]
    //         004e9d0a     XOR        EAX,EAX
    //         004e9d0c     TEST       this,this
    //         004e9d0e     JLE        LAB_004e9d2d
    //                               LAB_004e9d10                                                 XREF[1]:     004e9d2b(j)  
    //         004e9d10     CMP        EAX,EBP
    //         004e9d12     JGE        LAB_004e9d2d
    //         004e9d14     MOV        this,dword ptr [ESI + 0x238]
    //         004e9d1a     INC        EAX
    //         004e9d1b     MOV        EDX,dword ptr [this->_padding_ + EAX*0x4 + -0x4]
    //         004e9d1f     MOV        dword ptr [EDI + EAX*0x4 + -0x4],EDX
    //         004e9d23     MOV        this,dword ptr [ESI + 0x244]
    //         004e9d29     CMP        EAX,this
    //         004e9d2b     JL         LAB_004e9d10
    //                               LAB_004e9d2d                                                 XREF[2]:     004e9d0e(j), 004e9d12(j)  
    //         004e9d2d     MOV        EAX,dword ptr [ESI + 0x238]
    //         004e9d33     PUSH       EAX
    //         004e9d34     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004e9d39     ADD        ESP,0x4
    //         004e9d3c     MOV        dword ptr [ESI + 0x238],EDI
    //         004e9d42     MOV        dword ptr [ESI + 0x244],EBP
    //                               LAB_004e9d48                                                 XREF[2]:     004e9ce9(j), 004e9d02(j)  
    //         004e9d48     MOV        this,dword ptr [ESI + 0x238]
    //         004e9d4e     MOV        EAX,dword ptr [ESI + 0xf4]
    //         004e9d54     MOV        EDX,dword ptr [this->_padding_ + EBX*0x4]
    //         004e9d57     MOV        this,dword ptr [ESI + 0xf0]
    //         004e9d5d     PUSH       EDX
    //         004e9d5e     PUSH       EAX
    //         004e9d5f     MOV        EDX,dword ptr [this->_padding_ + 0x1256c]
    //         004e9d65     LEA        this,[ESI + 0x268]
    //         004e9d6b     PUSH       EDX
    //         004e9d6c     CALL       VictoryConditionRuleSystem::execute              int execute(VictoryConditionRuleSystem * this
    //                               LAB_004e9d71                                                 XREF[1]:     004e9cda(j)  
    //         004e9d71     MOV        EAX,dword ptr [ESI + 0x23c]
    //         004e9d77     INC        EBX
    //         004e9d78     CMP        EBX,EAX
    //         004e9d7a     JL         LAB_004e9c4d
    //                               LAB_004e9d80                                                 XREF[1]:     004e9c47(j)  
    //                              taistrmd.cpp:1352 (15)
    //         004e9d80     POP        EDI
    //         004e9d81     POP        ESI
    //         004e9d82     POP        EBP
    //         004e9d83     MOV        EAX,0x1
    //         004e9d88     POP        EBX
    //         004e9d89     ADD        ESP,0x8
    //         004e9d8c     RET        0x4
}

// Offset: 0x004E9D90
void setMainDecisionAI(TribeStrategyAIModule* this_, TribeMainDecisionAIModule* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TribeStrategyAIModule::setMainDecisionAI(class TribeMainDecisionAIModule *)   *
    //                              *********************************************************************************************************
    //                              void __thiscall setMainDecisionAI(TribeStrategyAIModule * this, Trib
    //              void              <VOID>         <RETURN>
    //              TribeStrategyA    ECX:4 (auto)   this
    //              TribeMainDecis    Stack[0x4]:4   param_1                   XREF[1]:     004e9d90(R)  
    //                               ?setMainDecisionAI@TribeStrategyAIModule@@QAEXPAVTribeMainD  XREF[2]:     TribeMainDecisionAIModule:004e49c1
    //                               TribeStrategyAIModule::setMainDecisionAI                                  TribeMainDecisionAIModule:004e4d08
    //                              taistrmd.cpp:1357 (10)
    //         004e9d90     MOV        EAX,dword ptr [ESP + param_1]
    //         004e9d94     MOV        dword ptr [ECX + this->md],EAX
    //                              taistrmd.cpp:1359 (3)
    //         004e9d9a     RET        0x4
}

// Offset: 0x004E9DA0
int TribeStrategyAIModule::save(int param_1) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: virtual int __thiscall TribeStrategyAIModule::save(int)                                       *
    //                              *********************************************************************************************************
    //                              int __thiscall save(TribeStrategyAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              TribeStrategyA    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[2]:     004e9daa(R), 004ea0e1(R)  
    //              char[257]         Stack[-0x108   tempString                XREF[14,4]:  004e9e9e(W), 004e9ea2(*), 004e9ed3(*), 004e9ed7(W), 
    //                                                                                     004e9f68(*), 004e9f73(W), 004e9f94(*), 004e9f9c(W), 
    //                                                                                     004ea029(*), 004ea034(W), 004ea055(*), 004ea05d(W), 
    //                                                                                     004ea0ee(*), 004ea0f9(W), 004e9e78(*), 004e9e8e(*), 
    //                                                                                     004e9ead(*), 004e9ebe(*)  
    //              int               Stack[-0x10c   tempInt
    //                               ?save@TribeStrategyAIModule@@UAEHH@Z                         XREF[1]:     005756d4(*)  
    //                               TribeStrategyAIModule::save
    //                              taistrmd.cpp:1364 (10)
    //         004e9da0     SUB        ESP,0x108
    //         004e9da6     PUSH       EBX
    //         004e9da7     MOV        EBX,this
    //         004e9da9     PUSH       EBP
    //                              taistrmd.cpp:1365 (27)
    //         004e9daa     MOV        EBP,dword ptr [ESP + param_1]
    //         004e9db1     PUSH       ESI
    //         004e9db2     PUSH       EDI
    //         004e9db3     LEA        EAX,[EBX + 0xf4]
    //         004e9db9     PUSH       0x4
    //         004e9dbb     PUSH       EAX
    //         004e9dbc     PUSH       EBP
    //         004e9dbd     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004e9dc2     ADD        ESP,0xc
    //                              taistrmd.cpp:1366 (18)
    //         004e9dc5     LEA        this,[EBX + 0x1fc]
    //         004e9dcb     PUSH       0x4
    //         004e9dcd     PUSH       this
    //         004e9dce     PUSH       EBP
    //         004e9dcf     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004e9dd4     ADD        ESP,0xc
    //                              taistrmd.cpp:1367 (18)
    //         004e9dd7     LEA        EDX,[EBX + 0x204]
    //         004e9ddd     PUSH       0x4
    //         004e9ddf     PUSH       EDX
    //         004e9de0     PUSH       EBP
    //         004e9de1     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004e9de6     ADD        ESP,0xc
    //                              taistrmd.cpp:1368 (18)
    //         004e9de9     LEA        EAX,[EBX + 0x208]
    //         004e9def     PUSH       0x4
    //         004e9df1     PUSH       EAX
    //         004e9df2     PUSH       EBP
    //         004e9df3     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004e9df8     ADD        ESP,0xc
    //                              taistrmd.cpp:1369 (18)
    //         004e9dfb     LEA        this,[EBX + 0x20c]
    //         004e9e01     PUSH       0x10
    //         004e9e03     PUSH       this
    //         004e9e04     PUSH       EBP
    //         004e9e05     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004e9e0a     ADD        ESP,0xc
    //                              taistrmd.cpp:1370 (18)
    //         004e9e0d     LEA        EDX,[EBX + 0x21c]
    //         004e9e13     PUSH       0x10
    //         004e9e15     PUSH       EDX
    //         004e9e16     PUSH       EBP
    //         004e9e17     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004e9e1c     ADD        ESP,0xc
    //                              taistrmd.cpp:1371 (18)
    //         004e9e1f     LEA        EAX,[EBX + 0x22c]
    //         004e9e25     PUSH       0x4
    //         004e9e27     PUSH       EAX
    //         004e9e28     PUSH       EBP
    //         004e9e29     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004e9e2e     ADD        ESP,0xc
    //                              taistrmd.cpp:1372 (18)
    //         004e9e31     LEA        this,[EBX + 0x230]
    //         004e9e37     PUSH       0x4
    //         004e9e39     PUSH       this
    //         004e9e3a     PUSH       EBP
    //         004e9e3b     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004e9e40     ADD        ESP,0xc
    //                              taistrmd.cpp:1373 (18)
    //         004e9e43     LEA        EDX,[EBX + 0x234]
    //         004e9e49     PUSH       0x4
    //         004e9e4b     PUSH       EDX
    //         004e9e4c     PUSH       EBP
    //         004e9e4d     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004e9e52     ADD        ESP,0xc
    //                              taistrmd.cpp:1374 (15)
    //         004e9e55     LEA        EAX,[EBX + 0x5f4]
    //         004e9e5b     PUSH       0x4
    //         004e9e5d     PUSH       EAX
    //         004e9e5e     PUSH       EBP
    //         004e9e5f     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              taistrmd.cpp:1376 (42)
    //         004e9e64     LEA        EDI,[EBX + 0xf8]
    //         004e9e6a     OR         this,0xffffffff
    //         004e9e6d     XOR        EAX,EAX
    //         004e9e6f     ADD        ESP,0xc
    //         004e9e72     SCASB.RE   ES:EDI
    //         004e9e74     NOT        this
    //         004e9e76     SUB        EDI,this
    //         004e9e78     LEA        EDX=>tempString[4],[ESP + 0x14]
    //         004e9e7c     MOV        EAX,this
    //         004e9e7e     MOV        ESI,EDI
    //         004e9e80     MOV        EDI,EDX
    //         004e9e82     SHR        this,0x2
    //         004e9e85     MOVSD.REP  ES:EDI,ESI
    //         004e9e87     MOV        this,EAX
    //         004e9e89     AND        this,0x3
    //         004e9e8c     MOVSB.REP  ES:EDI,ESI
    //                              taistrmd.cpp:1377 (9)
    //         004e9e8e     LEA        EDI=>tempString[4],[ESP + 0x14]
    //         004e9e92     OR         this,0xffffffff
    //         004e9e95     XOR        EAX,EAX
    //                              taistrmd.cpp:1378 (22)
    //         004e9e97     PUSH       0x4
    //         004e9e99     SCASB.RE   ES:EDI
    //         004e9e9b     NOT        this
    //         004e9e9d     DEC        this
    //         004e9e9e     MOV        dword ptr [ESP + tempString[0]],this
    //         004e9ea2     LEA        this=>tempString,[ESP + 0x14]
    //         004e9ea6     PUSH       this
    //         004e9ea7     PUSH       EBP
    //         004e9ea8     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              taistrmd.cpp:1379 (29)
    //         004e9ead     LEA        EDI=>tempString[4],[ESP + 0x20]
    //         004e9eb1     OR         this,0xffffffff
    //         004e9eb4     XOR        EAX,EAX
    //         004e9eb6     ADD        ESP,0xc
    //         004e9eb9     SCASB.RE   ES:EDI
    //         004e9ebb     NOT        this
    //         004e9ebd     DEC        this
    //         004e9ebe     LEA        EDX=>tempString[4],[ESP + 0x14]
    //         004e9ec2     PUSH       this
    //         004e9ec3     PUSH       EDX
    //         004e9ec4     PUSH       EBP
    //         004e9ec5     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              taistrmd.cpp:1381 (9)
    //         004e9eca     MOV        EAX,dword ptr [EBX + 0x23c]
    //         004e9ed0     ADD        ESP,0xc
    //                              taistrmd.cpp:1382 (17)
    //         004e9ed3     LEA        this=>tempString,[ESP + 0x10]
    //         004e9ed7     MOV        dword ptr [ESP + tempString[0]],EAX
    //         004e9edb     PUSH       0x4
    //         004e9edd     PUSH       this
    //         004e9ede     PUSH       EBP
    //         004e9edf     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              taistrmd.cpp:1383 (19)
    //         004e9ee4     MOV        EAX,dword ptr [EBX + 0x23c]
    //         004e9eea     ADD        ESP,0xc
    //         004e9eed     XOR        EDI,EDI
    //         004e9eef     TEST       EAX,EAX
    //         004e9ef1     JLE        LAB_004e9f8e
    //                               LAB_004e9ef7                                                 XREF[1]:     004e9f88(j)  
    //                              taistrmd.cpp:1384 (113)
    //         004e9ef7     MOV        EDX,dword ptr [EBX + 0x244]
    //         004e9efd     DEC        EDX
    //         004e9efe     CMP        EDI,EDX
    //         004e9f00     JLE        LAB_004e9f62
    //         004e9f02     LEA        EAX,[EDI*0x4 + 0x4]
    //         004e9f09     PUSH       EAX
    //         004e9f0a     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004e9f0f     MOV        ESI,EAX
    //         004e9f11     ADD        ESP,0x4
    //         004e9f14     TEST       ESI,ESI
    //         004e9f16     JZ         LAB_004e9f62
    //         004e9f18     MOV        this,dword ptr [EBX + 0x244]
    //         004e9f1e     XOR        EAX,EAX
    //         004e9f20     TEST       this,this
    //         004e9f22     JLE        LAB_004e9f44
    //                               LAB_004e9f24                                                 XREF[1]:     004e9f42(j)  
    //         004e9f24     LEA        this,[EDI + 0x1]
    //         004e9f27     CMP        EAX,this
    //         004e9f29     JGE        LAB_004e9f44
    //         004e9f2b     MOV        this,dword ptr [EBX + 0x238]
    //         004e9f31     INC        EAX
    //         004e9f32     MOV        EDX,dword ptr [this->_padding_ + EAX*0x4 + -0x4]
    //         004e9f36     MOV        dword ptr [ESI + EAX*0x4 + -0x4],EDX
    //         004e9f3a     MOV        this,dword ptr [EBX + 0x244]
    //         004e9f40     CMP        EAX,this
    //         004e9f42     JL         LAB_004e9f24
    //                               LAB_004e9f44                                                 XREF[2]:     004e9f22(j), 004e9f29(j)  
    //         004e9f44     MOV        EAX,dword ptr [EBX + 0x238]
    //         004e9f4a     PUSH       EAX
    //         004e9f4b     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004e9f50     LEA        EAX,[EDI + 0x1]
    //         004e9f53     ADD        ESP,0x4
    //         004e9f56     MOV        dword ptr [EBX + 0x238],ESI
    //         004e9f5c     MOV        dword ptr [EBX + 0x244],EAX
    //                               LAB_004e9f62                                                 XREF[2]:     004e9f00(j), 004e9f16(j)  
    //         004e9f62     MOV        this,dword ptr [EBX + 0x238]
    //                              taistrmd.cpp:1385 (38)
    //         004e9f68     LEA        EAX=>tempString,[ESP + 0x10]
    //         004e9f6c     PUSH       0x4
    //         004e9f6e     PUSH       EAX
    //         004e9f6f     MOV        EDX,dword ptr [this->_padding_ + EDI*0x4]
    //         004e9f72     PUSH       EBP
    //         004e9f73     MOV        dword ptr [ESP + tempString[0]],EDX
    //         004e9f77     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004e9f7c     MOV        EAX,dword ptr [EBX + 0x23c]
    //         004e9f82     ADD        ESP,0xc
    //         004e9f85     INC        EDI
    //         004e9f86     CMP        EDI,EAX
    //         004e9f88     JL         LAB_004e9ef7
    //                               LAB_004e9f8e                                                 XREF[1]:     004e9ef1(j)  
    //                              taistrmd.cpp:1387 (6)
    //         004e9f8e     MOV        this,dword ptr [EBX + 0x24c]
    //                              taistrmd.cpp:1388 (17)
    //         004e9f94     LEA        EDX=>tempString,[ESP + 0x10]
    //         004e9f98     PUSH       0x4
    //         004e9f9a     PUSH       EDX
    //         004e9f9b     PUSH       EBP
    //         004e9f9c     MOV        dword ptr [ESP + tempString[0]],this
    //         004e9fa0     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              taistrmd.cpp:1389 (19)
    //         004e9fa5     MOV        EAX,dword ptr [EBX + 0x24c]
    //         004e9fab     ADD        ESP,0xc
    //         004e9fae     XOR        EDI,EDI
    //         004e9fb0     TEST       EAX,EAX
    //         004e9fb2     JLE        LAB_004ea04f
    //                               LAB_004e9fb8                                                 XREF[1]:     004ea049(j)  
    //                              taistrmd.cpp:1390 (113)
    //         004e9fb8     MOV        EAX,dword ptr [EBX + 0x254]
    //         004e9fbe     DEC        EAX
    //         004e9fbf     CMP        EDI,EAX
    //         004e9fc1     JLE        LAB_004ea023
    //         004e9fc3     LEA        this,[EDI*0x4 + 0x4]
    //         004e9fca     PUSH       this
    //         004e9fcb     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004e9fd0     MOV        ESI,EAX
    //         004e9fd2     ADD        ESP,0x4
    //         004e9fd5     TEST       ESI,ESI
    //         004e9fd7     JZ         LAB_004ea023
    //         004e9fd9     MOV        this,dword ptr [EBX + 0x254]
    //         004e9fdf     XOR        EAX,EAX
    //         004e9fe1     TEST       this,this
    //         004e9fe3     JLE        LAB_004ea005
    //                               LAB_004e9fe5                                                 XREF[1]:     004ea003(j)  
    //         004e9fe5     LEA        this,[EDI + 0x1]
    //         004e9fe8     CMP        EAX,this
    //         004e9fea     JGE        LAB_004ea005
    //         004e9fec     MOV        EDX,dword ptr [EBX + 0x248]
    //         004e9ff2     INC        EAX
    //         004e9ff3     MOV        this,dword ptr [EDX + EAX*0x4 + -0x4]
    //         004e9ff7     MOV        dword ptr [ESI + EAX*0x4 + -0x4],this
    //         004e9ffb     MOV        this,dword ptr [EBX + 0x254]
    //         004ea001     CMP        EAX,this
    //         004ea003     JL         LAB_004e9fe5
    //                               LAB_004ea005                                                 XREF[2]:     004e9fe3(j), 004e9fea(j)  
    //         004ea005     MOV        EDX,dword ptr [EBX + 0x248]
    //         004ea00b     PUSH       EDX
    //         004ea00c     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004ea011     LEA        EAX,[EDI + 0x1]
    //         004ea014     ADD        ESP,0x4
    //         004ea017     MOV        dword ptr [EBX + 0x248],ESI
    //         004ea01d     MOV        dword ptr [EBX + 0x254],EAX
    //                               LAB_004ea023                                                 XREF[2]:     004e9fc1(j), 004e9fd7(j)  
    //         004ea023     MOV        EAX,dword ptr [EBX + 0x248]
    //                              taistrmd.cpp:1391 (38)
    //         004ea029     LEA        EDX=>tempString,[ESP + 0x10]
    //         004ea02d     PUSH       0x4
    //         004ea02f     PUSH       EDX
    //         004ea030     MOV        this,dword ptr [EAX + EDI*0x4]
    //         004ea033     PUSH       EBP
    //         004ea034     MOV        dword ptr [ESP + tempString[0]],this
    //         004ea038     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004ea03d     MOV        EAX,dword ptr [EBX + 0x24c]
    //         004ea043     ADD        ESP,0xc
    //         004ea046     INC        EDI
    //         004ea047     CMP        EDI,EAX
    //         004ea049     JL         LAB_004e9fb8
    //                               LAB_004ea04f                                                 XREF[1]:     004e9fb2(j)  
    //                              taistrmd.cpp:1393 (6)
    //         004ea04f     MOV        EAX,dword ptr [EBX + 0x25c]
    //                              taistrmd.cpp:1394 (17)
    //         004ea055     LEA        this=>tempString,[ESP + 0x10]
    //         004ea059     PUSH       0x4
    //         004ea05b     PUSH       this
    //         004ea05c     PUSH       EBP
    //         004ea05d     MOV        dword ptr [ESP + tempString[0]],EAX
    //         004ea061     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //                              taistrmd.cpp:1395 (19)
    //         004ea066     MOV        EAX,dword ptr [EBX + 0x25c]
    //         004ea06c     ADD        ESP,0xc
    //         004ea06f     XOR        EDI,EDI
    //         004ea071     TEST       EAX,EAX
    //         004ea073     JLE        LAB_004ea114
    //                               LAB_004ea079                                                 XREF[1]:     004ea10e(j)  
    //                              taistrmd.cpp:1396 (117)
    //         004ea079     MOV        EDX,dword ptr [EBX + 0x264]
    //         004ea07f     DEC        EDX
    //         004ea080     CMP        EDI,EDX
    //         004ea082     JLE        LAB_004ea0e8
    //         004ea084     LEA        EAX,[EDI*0x4 + 0x4]
    //         004ea08b     LEA        EBP,[EDI + 0x1]
    //         004ea08e     PUSH       EAX
    //         004ea08f     CALL       operator_new                                     void * operator_new(uint param_1)
    //         004ea094     MOV        ESI,EAX
    //         004ea096     ADD        ESP,0x4
    //         004ea099     TEST       ESI,ESI
    //         004ea09b     JZ         LAB_004ea0e1
    //         004ea09d     MOV        this,dword ptr [EBX + 0x264]
    //         004ea0a3     XOR        EAX,EAX
    //         004ea0a5     TEST       this,this
    //         004ea0a7     JLE        LAB_004ea0c6
    //                               LAB_004ea0a9                                                 XREF[1]:     004ea0c4(j)  
    //         004ea0a9     CMP        EAX,EBP
    //         004ea0ab     JGE        LAB_004ea0c6
    //         004ea0ad     MOV        this,dword ptr [EBX + 0x258]
    //         004ea0b3     INC        EAX
    //         004ea0b4     MOV        EDX,dword ptr [this->_padding_ + EAX*0x4 + -0x4]
    //         004ea0b8     MOV        dword ptr [ESI + EAX*0x4 + -0x4],EDX
    //         004ea0bc     MOV        this,dword ptr [EBX + 0x264]
    //         004ea0c2     CMP        EAX,this
    //         004ea0c4     JL         LAB_004ea0a9
    //                               LAB_004ea0c6                                                 XREF[2]:     004ea0a7(j), 004ea0ab(j)  
    //         004ea0c6     MOV        EAX,dword ptr [EBX + 0x258]
    //         004ea0cc     PUSH       EAX
    //         004ea0cd     CALL       operator_delete                                  void operator_delete(void * param_1)
    //         004ea0d2     ADD        ESP,0x4
    //         004ea0d5     MOV        dword ptr [EBX + 0x258],ESI
    //         004ea0db     MOV        dword ptr [EBX + 0x264],EBP
    //                               LAB_004ea0e1                                                 XREF[1]:     004ea09b(j)  
    //         004ea0e1     MOV        EBP,dword ptr [ESP + param_1]
    //                               LAB_004ea0e8                                                 XREF[1]:     004ea082(j)  
    //         004ea0e8     MOV        this,dword ptr [EBX + 0x258]
    //                              taistrmd.cpp:1397 (38)
    //         004ea0ee     LEA        EAX=>tempString,[ESP + 0x10]
    //         004ea0f2     PUSH       0x4
    //         004ea0f4     PUSH       EAX
    //         004ea0f5     MOV        EDX,dword ptr [this->_padding_ + EDI*0x4]
    //         004ea0f8     PUSH       EBP
    //         004ea0f9     MOV        dword ptr [ESP + tempString[0]],EDX
    //         004ea0fd     CALL       rge_write                                        void rge_write(int param_1, void * param_2, i
    //         004ea102     MOV        EAX,dword ptr [EBX + 0x25c]
    //         004ea108     ADD        ESP,0xc
    //         004ea10b     INC        EDI
    //         004ea10c     CMP        EDI,EAX
    //         004ea10e     JL         LAB_004ea079
    //                               LAB_004ea114                                                 XREF[1]:     004ea073(j)  
    //                              taistrmd.cpp:1400 (18)
    //         004ea114     POP        EDI
    //         004ea115     POP        ESI
    //         004ea116     POP        EBP
    //         004ea117     MOV        EAX,0x1
    //         004ea11c     POP        EBX
    //         004ea11d     ADD        ESP,0x108
    //         004ea123     RET        0x4
}

// Offset: 0x004EA130
char* ruleSetName(TribeStrategyAIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: char * __thiscall TribeStrategyAIModule::ruleSetName(void)                                    *
    //                              *********************************************************************************************************
    //                              char * __thiscall ruleSetName(TribeStrategyAIModule * this)
    //              char *            EAX:4          <RETURN>
    //              TribeStrategyA    ECX:4 (auto)   this
    //                               ?ruleSetName@TribeStrategyAIModule@@QAEPADXZ                 XREF[2]:     aiStatus:00514f65(c), 
    //                               TribeStrategyAIModule::ruleSetName                                        logStatus:00518fd4(c)  
    //                              taistrmd.cpp:1405 (6)
    //         004ea130     LEA        EAX,[ECX + this->ruleSetNameValue[0]]
    //                              taistrmd.cpp:1407 (1)
    //         004ea136     RET
}

// Offset: 0x004EA140
int loadRules(TribeStrategyAIModule* this_, char* param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TribeStrategyAIModule::loadRules(char *)                                       *
    //                              *********************************************************************************************************
    //                              int __thiscall loadRules(TribeStrategyAIModule * this, char * param_1)
    //              int               EAX:4          <RETURN>
    //              TribeStrategyA    ECX:4 (auto)   this
    //              char *            Stack[0x4]:4   param_1                   XREF[1]:     004ea140(R)  
    //                               ?loadRules@TribeStrategyAIModule@@QAEHPAD@Z                  XREF[2]:     TribeStrategyAIModule:004e93fd(c), 
    //                               TribeStrategyAIModule::loadRules                                          loadAIInformation:00515800(c)  
    //                              taistrmd.cpp:1412 (11)
    //         004ea140     MOV        EAX,dword ptr [ESP + param_1]
    //         004ea144     PUSH       EDI
    //         004ea145     TEST       EAX,EAX
    //         004ea147     MOV        EDI,this
    //         004ea149     JNZ        LAB_004ea14f
    //                              taistrmd.cpp:1420 (4)
    //         004ea14b     POP        EDI
    //         004ea14c     RET        0x4
    //                               LAB_004ea14f                                                 XREF[1]:     004ea149(j)  
    //                              taistrmd.cpp:1412 (1)
    //         004ea14f     PUSH       ESI
    //                              taistrmd.cpp:1417 (21)
    //         004ea150     LEA        ESI,[EDI + 0xf8]
    //         004ea156     PUSH       0xff
    //         004ea15b     PUSH       EAX
    //         004ea15c     PUSH       ESI
    //         004ea15d     CALL       strncpy                                          undefined strncpy()
    //         004ea162     ADD        ESP,0xc
    //                              taistrmd.cpp:1418 (13)
    //         004ea165     LEA        this,[EDI + 0x268]
    //         004ea16b     PUSH       ESI
    //         004ea16c     CALL       VictoryConditionRuleSystem::loadRules            int loadRules(VictoryConditionRuleSystem * th
    //         004ea171     POP        ESI
    //                              taistrmd.cpp:1420 (4)
    //         004ea172     POP        EDI
    //         004ea173     RET        0x4
}

// Offset: 0x004EA180
void setRule(TribeStrategyAIModule* this_, int param_2, int param_3) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TribeStrategyAIModule::setRule(int,int)                                       *
    //                              *********************************************************************************************************
    //                              void __thiscall setRule(TribeStrategyAIModule * this, int param_1, i
    //              void              <VOID>         <RETURN>
    //              TribeStrategyA    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004ea181(R)  
    //              int               Stack[0x8]:4   param_2                   XREF[1]:     004ea187(R)  
    //                               ?setRule@TribeStrategyAIModule@@QAEXHH@Z                     XREF[69]:    intelligentBuildListAndRulesSelect
    //                               TribeStrategyAIModule::setRule                                            intelligentBuildListAndRulesSelect
    //                                                                                                         intelligentBuildListAndRulesSelect
    //                                                                                                         intelligentBuildListAndRulesSelect
    //                                                                                                         intelligentBuildListAndRulesSelect
    //                                                                                                         intelligentBuildListAndRulesSelect
    //                                                                                                         intelligentBuildListAndRulesSelect
    //                                                                                                         intelligentBuildListAndRulesSelect
    //                                                                                                         intelligentBuildListAndRulesSelect
    //                                                                                                         intelligentBuildListAndRulesSelect
    //                                                                                                         intelligentBuildListAndRulesSelect
    //                                                                                                         intelligentBuildListAndRulesSelect
    //                                                                                                         intelligentBuildListAndRulesSelect
    //                                                                                                         intelligentBuildListAndRulesSelect
    //                                                                                                         intelligentBuildListAndRulesSelect
    //                                                                                                         intelligentBuildListAndRulesSelect
    //                                                                                                         intelligentBuildListAndRulesSelect
    //                                                                                                         intelligentBuildListAndRulesSelect
    //                                                                                                         intelligentBuildListAndRulesSelect
    //                                                                                                         intelligentBuildListAndRulesSelect
    //                                                                                                         [more]
    //                              taistrmd.cpp:1425 (1)
    //         004ea180     PUSH       EBX
    //                              taistrmd.cpp:1426 (28)
    //         004ea181     MOV        EBX,dword ptr [ESP + param_1]
    //         004ea185     PUSH       ESI
    //         004ea186     PUSH       EDI
    //         004ea187     MOV        EDI,dword ptr [ESP + param_2]
    //         004ea18b     MOV        ESI,this
    //         004ea18d     PUSH       EDI
    //         004ea18e     PUSH       EBX
    //         004ea18f     PUSH       s_Setting_SN[%d]_to_%d.                          = "Setting SN[%d] to %d."
    //         004ea194     PUSH       ESI
    //         004ea195     CALL       AIModule::logCommonHistory                       void logCommonHistory(AIModule * this, char *
    //         004ea19a     ADD        ESP,0x10
    //                              taistrmd.cpp:1427 (13)
    //         004ea19d     LEA        this,[ESI + 0x268]
    //         004ea1a3     PUSH       EDI
    //         004ea1a4     PUSH       EBX
    //         004ea1a5     CALL       VictoryConditionRuleSystem::setRule              void setRule(VictoryConditionRuleSystem * thi
    //                              taistrmd.cpp:1428 (6)
    //         004ea1aa     POP        EDI
    //         004ea1ab     POP        ESI
    //         004ea1ac     POP        EBX
    //         004ea1ad     RET        0x8
}

// Offset: 0x004EA1B0
int rule(TribeStrategyAIModule* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TribeStrategyAIModule::rule(int)                                               *
    //                              *********************************************************************************************************
    //                              int __thiscall rule(TribeStrategyAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              TribeStrategyA    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004ea1b0(R)  
    //                               ?rule@TribeStrategyAIModule@@QAEHH@Z                         XREF[8]:     intelligentBuildListAndRulesSelect
    //                               TribeStrategyAIModule::rule                                               intelligentBuildListAndRulesSelect
    //                                                                                                         intelligentBuildListAndRulesSelect
    //                                                                                                         intelligentBuildListAndRulesSelect
    //                                                                                                         intelligentBuildListAndRulesSelect
    //                                                                                                         intelligentBuildListAndRulesSelect
    //                                                                                                         intelligentBuildListAndRulesSelect
    //                                                                                                         intelligentBuildListAndRulesSelect
    //                              taistrmd.cpp:1433 (16)
    //         004ea1b0     MOV        EAX,dword ptr [ESP + param_1]
    //         004ea1b4     ADD        this,0x268
    //         004ea1ba     PUSH       EAX
    //         004ea1bb     CALL       VictoryConditionRuleSystem::rule                 int rule(VictoryConditionRuleSystem * this, i
    //                              taistrmd.cpp:1435 (3)
    //         004ea1c0     RET        0x4
}

// Offset: 0x004EA1D0
void setDifficultyLevel(TribeStrategyAIModule* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TribeStrategyAIModule::setDifficultyLevel(int)                                *
    //                              *********************************************************************************************************
    //                              void __thiscall setDifficultyLevel(TribeStrategyAIModule * this, int
    //              void              <VOID>         <RETURN>
    //              TribeStrategyA    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004ea1d0(R)  
    //                               ?setDifficultyLevel@TribeStrategyAIModule@@QAEXH@Z           XREF[2]:     TribeStrategyAIModule:004e9407(c), 
    //                               TribeStrategyAIModule::setDifficultyLevel                                 loadAIInformation:0051584a(c)  
    //                              taistrmd.cpp:1440 (16)
    //         004ea1d0     MOV        EAX,dword ptr [ESP + param_1]
    //         004ea1d4     ADD        this,0x268
    //         004ea1da     PUSH       EAX
    //         004ea1db     CALL       VictoryConditionRuleSystem::modifyForDifficult   void modifyForDifficultyLevel(VictoryConditio
    //                              taistrmd.cpp:1444 (3)
    //         004ea1e0     RET        0x4
}

// Offset: 0x004EA1F0
int currentVictoryCondition(TribeStrategyAIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TribeStrategyAIModule::currentVictoryCondition(void)const                      *
    //                              *********************************************************************************************************
    //                              int __thiscall currentVictoryCondition(TribeStrategyAIModule * this)
    //              int               EAX:4          <RETURN>
    //              TribeStrategyA    ECX:4 (auto)   this
    //                               ?currentVictoryCondition@TribeStrategyAIModule@@QBEHXZ       XREF[7]:     taskIdleSoldiers:004f207a(c), 
    //                               TribeStrategyAIModule::currentVictoryCondition                            taskIdleSoldiers:004f20b5(c), 
    //                                                                                                         taskActiveSoldiers:004f28d4(c), 
    //                                                                                                         taskActiveSoldiers:004f2964(c), 
    //                                                                                                         taskActiveSoldiers:004f2d55(c), 
    //                                                                                                         itemToCapture:00500a40(c), 
    //                                                                                                         itemToBringToArea:00500a90(c)  
    //                              taistrmd.cpp:1449 (6)
    //         004ea1f0     MOV        EAX,dword ptr [ECX + this->currentVictoryCondi
    //                              taistrmd.cpp:1451 (1)
    //         004ea1f6     RET
}

// Offset: 0x004EA200
int targetID(TribeStrategyAIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TribeStrategyAIModule::targetID(void)const                                     *
    //                              *********************************************************************************************************
    //                              int __thiscall targetID(TribeStrategyAIModule * this)
    //              int               EAX:4          <RETURN>
    //              TribeStrategyA    ECX:4 (auto)   this
    //                               ?targetID@TribeStrategyAIModule@@QBEHXZ                      XREF[1]:     itemToCapture:00500a55(c)  
    //                               TribeStrategyAIModule::targetID
    //                              taistrmd.cpp:1456 (6)
    //         004ea200     MOV        EAX,dword ptr [ECX + this->targetIDValue]
    //                              taistrmd.cpp:1458 (1)
    //         004ea206     RET
}

// Offset: 0x004EA210
int targetType(TribeStrategyAIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TribeStrategyAIModule::targetType(void)const                                   *
    //                              *********************************************************************************************************
    //                              int __thiscall targetType(TribeStrategyAIModule * this)
    //              int               EAX:4          <RETURN>
    //              TribeStrategyA    ECX:4 (auto)   this
    //                               ?targetType@TribeStrategyAIModule@@QBEHXZ
    //                               TribeStrategyAIModule::targetType
    //                              taistrmd.cpp:1463 (6)
    //         004ea210     MOV        EAX,dword ptr [ECX + this->targetTypeValue]
    //                              taistrmd.cpp:1465 (1)
    //         004ea216     RET
}

// Offset: 0x004EA220
int secondTargetID(TribeStrategyAIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TribeStrategyAIModule::secondTargetID(void)const                               *
    //                              *********************************************************************************************************
    //                              int __thiscall secondTargetID(TribeStrategyAIModule * this)
    //              int               EAX:4          <RETURN>
    //              TribeStrategyA    ECX:4 (auto)   this
    //                               ?secondTargetID@TribeStrategyAIModule@@QBEHXZ                XREF[1]:     itemToBringToArea:00500aa6(c)  
    //                               TribeStrategyAIModule::secondTargetID
    //                              taistrmd.cpp:1470 (6)
    //         004ea220     MOV        EAX,dword ptr [ECX + this->secondTargetIDValue]
    //                              taistrmd.cpp:1472 (1)
    //         004ea226     RET
}

// Offset: 0x004EA230
int secondTargetType(TribeStrategyAIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TribeStrategyAIModule::secondTargetType(void)const                             *
    //                              *********************************************************************************************************
    //                              int __thiscall secondTargetType(TribeStrategyAIModule * this)
    //              int               EAX:4          <RETURN>
    //              TribeStrategyA    ECX:4 (auto)   this
    //                               ?secondTargetType@TribeStrategyAIModule@@QBEHXZ
    //                               TribeStrategyAIModule::secondTargetType
    //                              taistrmd.cpp:1477 (6)
    //         004ea230     MOV        EAX,dword ptr [ECX + this->secondTargetTypeVal
    //                              taistrmd.cpp:1479 (1)
    //         004ea236     RET
}

// Offset: 0x004EA240
Waypoint* targetPoint1(TribeStrategyAIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: struct Waypoint const & __thiscall TribeStrategyAIModule::targetPoint1(void)const             *
    //                              *********************************************************************************************************
    //                              Waypoint * __thiscall targetPoint1(TribeStrategyAIModule * this)
    //              Waypoint *        EAX:4          <RETURN>
    //              TribeStrategyA    ECX:4 (auto)   this
    //                               ?targetPoint1@TribeStrategyAIModule@@QBEABUWaypoint@@XZ      XREF[1]:     taskActiveSoldiers:004f3f07(c)  
    //                               TribeStrategyAIModule::targetPoint1
    //                              taistrmd.cpp:1484 (6)
    //         004ea240     LEA        EAX,[ECX + this->targetPoint1Value.x]
    //                              taistrmd.cpp:1486 (1)
    //         004ea246     RET
}

// Offset: 0x004EA250
Waypoint* targetPoint2(TribeStrategyAIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: struct Waypoint const & __thiscall TribeStrategyAIModule::targetPoint2(void)const             *
    //                              *********************************************************************************************************
    //                              Waypoint * __thiscall targetPoint2(TribeStrategyAIModule * this)
    //              Waypoint *        EAX:4          <RETURN>
    //              TribeStrategyA    ECX:4 (auto)   this
    //                               ?targetPoint2@TribeStrategyAIModule@@QBEABUWaypoint@@XZ      XREF[1]:     taskActiveSoldiers:004f3f3f(c)  
    //                               TribeStrategyAIModule::targetPoint2
    //                              taistrmd.cpp:1491 (6)
    //         004ea250     LEA        EAX,[ECX + this->targetPoint2Value.x]
    //                              taistrmd.cpp:1493 (1)
    //         004ea256     RET
}

// Offset: 0x004EA260
int targetAttribute(TribeStrategyAIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TribeStrategyAIModule::targetAttribute(void)const                              *
    //                              *********************************************************************************************************
    //                              int __thiscall targetAttribute(TribeStrategyAIModule * this)
    //              int               EAX:4          <RETURN>
    //              TribeStrategyA    ECX:4 (auto)   this
    //                               ?targetAttribute@TribeStrategyAIModule@@QBEHXZ
    //                               TribeStrategyAIModule::targetAttribute
    //                              taistrmd.cpp:1498 (6)
    //         004ea260     MOV        EAX,dword ptr [ECX + this->targetAttributeValue]
    //                              taistrmd.cpp:1500 (1)
    //         004ea266     RET
}

// Offset: 0x004EA270
int targetNumber(TribeStrategyAIModule* this_) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TribeStrategyAIModule::targetNumber(void)const                                 *
    //                              *********************************************************************************************************
    //                              int __thiscall targetNumber(TribeStrategyAIModule * this)
    //              int               EAX:4          <RETURN>
    //              TribeStrategyA    ECX:4 (auto)   this
    //                               ?targetNumber@TribeStrategyAIModule@@QBEHXZ
    //                               TribeStrategyAIModule::targetNumber
    //                              taistrmd.cpp:1505 (6)
    //         004ea270     MOV        EAX,dword ptr [ECX + this->targetNumberValue]
    //                              taistrmd.cpp:1507 (1)
    //         004ea276     RET
}

// Offset: 0x004EA280
void setVictoryCondition(TribeStrategyAIModule* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: void __thiscall TribeStrategyAIModule::setVictoryCondition(int)                               *
    //                              *********************************************************************************************************
    //                              void __thiscall setVictoryCondition(TribeStrategyAIModule * this, in
    //              void              <VOID>         <RETURN>
    //              TribeStrategyA    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[40]:    004ea280(R), 004ea289(*), 004ea2a5(W), 004ea2d0(R), 
    //                                                                                     004ea2de(*), 004ea2e5(W), 004ea310(R), 004ea31e(*), 
    //                                                                                     004ea325(W), 004ea350(R), 004ea35e(*), 004ea365(W), 
    //                                                                                     004ea390(R), 004ea39e(*), 004ea3a5(W), 004ea3d0(R), 
    //                                                                                     004ea3de(*), 004ea3e5(W), 004ea410(R), 004ea41e(*)  
    //                               ?setVictoryCondition@TribeStrategyAIModule@@QAEXH@Z          XREF[1]:     update:004e9901(c)  
    //                               TribeStrategyAIModule::setVictoryCondition
    //                              taistrmd.cpp:1512 (9)
    //         004ea280     MOV        EAX,dword ptr [ESP + param_1]
    //         004ea284     PUSH       EBX
    //         004ea285     MOV        EBX,this
    //         004ea287     PUSH       EBP
    //         004ea288     PUSH       ESI
    //                              taistrmd.cpp:1551 (85)
    //         004ea289     LEA        this=>param_1,[ESP + 0x10]
    //         004ea28d     PUSH       EDI
    //         004ea28e     LEA        ESI,[EBX + 0x238]
    //         004ea294     XOR        EDI,EDI
    //         004ea296     PUSH       this
    //         004ea297     MOV        dword ptr [EBX + 0xf4],EAX
    //         004ea29d     MOV        this,ESI
    //         004ea29f     MOV        dword ptr [EBX + 0x23c],EDI
    //         004ea2a5     MOV        dword ptr [ESP + param_1],0x1
    //         004ea2ad     CALL       ManagedArray<int>::contains                      int contains(ManagedArray<int> * this, int * 
    //         004ea2b2     CMP        EAX,0x1
    //         004ea2b5     JZ         LAB_004ea2de
    //         004ea2b7     MOV        EDX,dword ptr [ESI + 0xc]
    //         004ea2ba     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ea2bd     DEC        EDX
    //         004ea2be     CMP        EAX,EDX
    //         004ea2c0     JLE        LAB_004ea2cb
    //         004ea2c2     INC        EAX
    //         004ea2c3     MOV        this,ESI
    //         004ea2c5     PUSH       EAX
    //         004ea2c6     CALL       ManagedArray<int>::resize                        int resize(ManagedArray<int> * this, int para
    //                               LAB_004ea2cb                                                 XREF[1]:     004ea2c0(j)  
    //         004ea2cb     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ea2ce     MOV        this,dword ptr [ESI]
    //         004ea2d0     MOV        EDX,dword ptr [ESP + param_1]
    //         004ea2d4     MOV        dword ptr [this->_padding_ + EAX*0x4],EDX
    //         004ea2d7     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ea2da     INC        EAX
    //         004ea2db     MOV        dword ptr [ESI + 0x4],EAX
    //                               LAB_004ea2de                                                 XREF[1]:     004ea2b5(j)  
    //                              taistrmd.cpp:1552 (64)
    //         004ea2de     LEA        EAX=>param_1,[ESP + 0x14]
    //         004ea2e2     MOV        this,ESI
    //         004ea2e4     PUSH       EAX
    //         004ea2e5     MOV        dword ptr [ESP + param_1],0x2
    //         004ea2ed     CALL       ManagedArray<int>::contains                      int contains(ManagedArray<int> * this, int * 
    //         004ea2f2     CMP        EAX,0x1
    //         004ea2f5     JZ         LAB_004ea31e
    //         004ea2f7     MOV        this,dword ptr [ESI + 0xc]
    //         004ea2fa     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ea2fd     DEC        this
    //         004ea2fe     CMP        EAX,this
    //         004ea300     JLE        LAB_004ea30b
    //         004ea302     INC        EAX
    //         004ea303     MOV        this,ESI
    //         004ea305     PUSH       EAX
    //         004ea306     CALL       ManagedArray<int>::resize                        int resize(ManagedArray<int> * this, int para
    //                               LAB_004ea30b                                                 XREF[1]:     004ea300(j)  
    //         004ea30b     MOV        EDX,dword ptr [ESI + 0x4]
    //         004ea30e     MOV        EAX,dword ptr [ESI]
    //         004ea310     MOV        this,dword ptr [ESP + param_1]
    //         004ea314     MOV        dword ptr [EAX + EDX*0x4],this
    //         004ea317     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ea31a     INC        EAX
    //         004ea31b     MOV        dword ptr [ESI + 0x4],EAX
    //                               LAB_004ea31e                                                 XREF[1]:     004ea2f5(j)  
    //                              taistrmd.cpp:1553 (64)
    //         004ea31e     LEA        EDX=>param_1,[ESP + 0x14]
    //         004ea322     MOV        this,ESI
    //         004ea324     PUSH       EDX
    //         004ea325     MOV        dword ptr [ESP + param_1],0xc
    //         004ea32d     CALL       ManagedArray<int>::contains                      int contains(ManagedArray<int> * this, int * 
    //         004ea332     CMP        EAX,0x1
    //         004ea335     JZ         LAB_004ea35e
    //         004ea337     MOV        this,dword ptr [ESI + 0xc]
    //         004ea33a     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ea33d     DEC        this
    //         004ea33e     CMP        EAX,this
    //         004ea340     JLE        LAB_004ea34b
    //         004ea342     INC        EAX
    //         004ea343     MOV        this,ESI
    //         004ea345     PUSH       EAX
    //         004ea346     CALL       ManagedArray<int>::resize                        int resize(ManagedArray<int> * this, int para
    //                               LAB_004ea34b                                                 XREF[1]:     004ea340(j)  
    //         004ea34b     MOV        EDX,dword ptr [ESI + 0x4]
    //         004ea34e     MOV        EAX,dword ptr [ESI]
    //         004ea350     MOV        this,dword ptr [ESP + param_1]
    //         004ea354     MOV        dword ptr [EAX + EDX*0x4],this
    //         004ea357     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ea35a     INC        EAX
    //         004ea35b     MOV        dword ptr [ESI + 0x4],EAX
    //                               LAB_004ea35e                                                 XREF[1]:     004ea335(j)  
    //                              taistrmd.cpp:1554 (64)
    //         004ea35e     LEA        EDX=>param_1,[ESP + 0x14]
    //         004ea362     MOV        this,ESI
    //         004ea364     PUSH       EDX
    //         004ea365     MOV        dword ptr [ESP + param_1],0xd
    //         004ea36d     CALL       ManagedArray<int>::contains                      int contains(ManagedArray<int> * this, int * 
    //         004ea372     CMP        EAX,0x1
    //         004ea375     JZ         LAB_004ea39e
    //         004ea377     MOV        this,dword ptr [ESI + 0xc]
    //         004ea37a     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ea37d     DEC        this
    //         004ea37e     CMP        EAX,this
    //         004ea380     JLE        LAB_004ea38b
    //         004ea382     INC        EAX
    //         004ea383     MOV        this,ESI
    //         004ea385     PUSH       EAX
    //         004ea386     CALL       ManagedArray<int>::resize                        int resize(ManagedArray<int> * this, int para
    //                               LAB_004ea38b                                                 XREF[1]:     004ea380(j)  
    //         004ea38b     MOV        EDX,dword ptr [ESI + 0x4]
    //         004ea38e     MOV        EAX,dword ptr [ESI]
    //         004ea390     MOV        this,dword ptr [ESP + param_1]
    //         004ea394     MOV        dword ptr [EAX + EDX*0x4],this
    //         004ea397     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ea39a     INC        EAX
    //         004ea39b     MOV        dword ptr [ESI + 0x4],EAX
    //                               LAB_004ea39e                                                 XREF[1]:     004ea375(j)  
    //                              taistrmd.cpp:1555 (64)
    //         004ea39e     LEA        EDX=>param_1,[ESP + 0x14]
    //         004ea3a2     MOV        this,ESI
    //         004ea3a4     PUSH       EDX
    //         004ea3a5     MOV        dword ptr [ESP + param_1],0xe
    //         004ea3ad     CALL       ManagedArray<int>::contains                      int contains(ManagedArray<int> * this, int * 
    //         004ea3b2     CMP        EAX,0x1
    //         004ea3b5     JZ         LAB_004ea3de
    //         004ea3b7     MOV        this,dword ptr [ESI + 0xc]
    //         004ea3ba     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ea3bd     DEC        this
    //         004ea3be     CMP        EAX,this
    //         004ea3c0     JLE        LAB_004ea3cb
    //         004ea3c2     INC        EAX
    //         004ea3c3     MOV        this,ESI
    //         004ea3c5     PUSH       EAX
    //         004ea3c6     CALL       ManagedArray<int>::resize                        int resize(ManagedArray<int> * this, int para
    //                               LAB_004ea3cb                                                 XREF[1]:     004ea3c0(j)  
    //         004ea3cb     MOV        EDX,dword ptr [ESI + 0x4]
    //         004ea3ce     MOV        EAX,dword ptr [ESI]
    //         004ea3d0     MOV        this,dword ptr [ESP + param_1]
    //         004ea3d4     MOV        dword ptr [EAX + EDX*0x4],this
    //         004ea3d7     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ea3da     INC        EAX
    //         004ea3db     MOV        dword ptr [ESI + 0x4],EAX
    //                               LAB_004ea3de                                                 XREF[1]:     004ea3b5(j)  
    //                              taistrmd.cpp:1556 (64)
    //         004ea3de     LEA        EDX=>param_1,[ESP + 0x14]
    //         004ea3e2     MOV        this,ESI
    //         004ea3e4     PUSH       EDX
    //         004ea3e5     MOV        dword ptr [ESP + param_1],0x10
    //         004ea3ed     CALL       ManagedArray<int>::contains                      int contains(ManagedArray<int> * this, int * 
    //         004ea3f2     CMP        EAX,0x1
    //         004ea3f5     JZ         LAB_004ea41e
    //         004ea3f7     MOV        this,dword ptr [ESI + 0xc]
    //         004ea3fa     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ea3fd     DEC        this
    //         004ea3fe     CMP        EAX,this
    //         004ea400     JLE        LAB_004ea40b
    //         004ea402     INC        EAX
    //         004ea403     MOV        this,ESI
    //         004ea405     PUSH       EAX
    //         004ea406     CALL       ManagedArray<int>::resize                        int resize(ManagedArray<int> * this, int para
    //                               LAB_004ea40b                                                 XREF[1]:     004ea400(j)  
    //         004ea40b     MOV        EDX,dword ptr [ESI + 0x4]
    //         004ea40e     MOV        EAX,dword ptr [ESI]
    //         004ea410     MOV        this,dword ptr [ESP + param_1]
    //         004ea414     MOV        dword ptr [EAX + EDX*0x4],this
    //         004ea417     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ea41a     INC        EAX
    //         004ea41b     MOV        dword ptr [ESI + 0x4],EAX
    //                               LAB_004ea41e                                                 XREF[1]:     004ea3f5(j)  
    //                              taistrmd.cpp:1557 (64)
    //         004ea41e     LEA        EDX=>param_1,[ESP + 0x14]
    //         004ea422     MOV        this,ESI
    //         004ea424     PUSH       EDX
    //         004ea425     MOV        dword ptr [ESP + param_1],0x11
    //         004ea42d     CALL       ManagedArray<int>::contains                      int contains(ManagedArray<int> * this, int * 
    //         004ea432     CMP        EAX,0x1
    //         004ea435     JZ         LAB_004ea45e
    //         004ea437     MOV        this,dword ptr [ESI + 0xc]
    //         004ea43a     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ea43d     DEC        this
    //         004ea43e     CMP        EAX,this
    //         004ea440     JLE        LAB_004ea44b
    //         004ea442     INC        EAX
    //         004ea443     MOV        this,ESI
    //         004ea445     PUSH       EAX
    //         004ea446     CALL       ManagedArray<int>::resize                        int resize(ManagedArray<int> * this, int para
    //                               LAB_004ea44b                                                 XREF[1]:     004ea440(j)  
    //         004ea44b     MOV        EDX,dword ptr [ESI + 0x4]
    //         004ea44e     MOV        EAX,dword ptr [ESI]
    //         004ea450     MOV        this,dword ptr [ESP + param_1]
    //         004ea454     MOV        dword ptr [EAX + EDX*0x4],this
    //         004ea457     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ea45a     INC        EAX
    //         004ea45b     MOV        dword ptr [ESI + 0x4],EAX
    //                               LAB_004ea45e                                                 XREF[1]:     004ea435(j)  
    //                              taistrmd.cpp:1558 (64)
    //         004ea45e     LEA        EDX=>param_1,[ESP + 0x14]
    //         004ea462     MOV        this,ESI
    //         004ea464     PUSH       EDX
    //         004ea465     MOV        dword ptr [ESP + param_1],0x12
    //         004ea46d     CALL       ManagedArray<int>::contains                      int contains(ManagedArray<int> * this, int * 
    //         004ea472     CMP        EAX,0x1
    //         004ea475     JZ         LAB_004ea49e
    //         004ea477     MOV        this,dword ptr [ESI + 0xc]
    //         004ea47a     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ea47d     DEC        this
    //         004ea47e     CMP        EAX,this
    //         004ea480     JLE        LAB_004ea48b
    //         004ea482     INC        EAX
    //         004ea483     MOV        this,ESI
    //         004ea485     PUSH       EAX
    //         004ea486     CALL       ManagedArray<int>::resize                        int resize(ManagedArray<int> * this, int para
    //                               LAB_004ea48b                                                 XREF[1]:     004ea480(j)  
    //         004ea48b     MOV        EDX,dword ptr [ESI + 0x4]
    //         004ea48e     MOV        EAX,dword ptr [ESI]
    //         004ea490     MOV        this,dword ptr [ESP + param_1]
    //         004ea494     MOV        dword ptr [EAX + EDX*0x4],this
    //         004ea497     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ea49a     INC        EAX
    //         004ea49b     MOV        dword ptr [ESI + 0x4],EAX
    //                               LAB_004ea49e                                                 XREF[1]:     004ea475(j)  
    //                              taistrmd.cpp:1559 (64)
    //         004ea49e     LEA        EDX=>param_1,[ESP + 0x14]
    //         004ea4a2     MOV        this,ESI
    //         004ea4a4     PUSH       EDX
    //         004ea4a5     MOV        dword ptr [ESP + param_1],0x15
    //         004ea4ad     CALL       ManagedArray<int>::contains                      int contains(ManagedArray<int> * this, int * 
    //         004ea4b2     CMP        EAX,0x1
    //         004ea4b5     JZ         LAB_004ea4de
    //         004ea4b7     MOV        this,dword ptr [ESI + 0xc]
    //         004ea4ba     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ea4bd     DEC        this
    //         004ea4be     CMP        EAX,this
    //         004ea4c0     JLE        LAB_004ea4cb
    //         004ea4c2     INC        EAX
    //         004ea4c3     MOV        this,ESI
    //         004ea4c5     PUSH       EAX
    //         004ea4c6     CALL       ManagedArray<int>::resize                        int resize(ManagedArray<int> * this, int para
    //                               LAB_004ea4cb                                                 XREF[1]:     004ea4c0(j)  
    //         004ea4cb     MOV        EDX,dword ptr [ESI + 0x4]
    //         004ea4ce     MOV        EAX,dword ptr [ESI]
    //         004ea4d0     MOV        this,dword ptr [ESP + param_1]
    //         004ea4d4     MOV        dword ptr [EAX + EDX*0x4],this
    //         004ea4d7     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ea4da     INC        EAX
    //         004ea4db     MOV        dword ptr [ESI + 0x4],EAX
    //                               LAB_004ea4de                                                 XREF[1]:     004ea4b5(j)  
    //                              taistrmd.cpp:1560 (64)
    //         004ea4de     LEA        EDX=>param_1,[ESP + 0x14]
    //         004ea4e2     MOV        this,ESI
    //         004ea4e4     PUSH       EDX
    //         004ea4e5     MOV        dword ptr [ESP + param_1],0x16
    //         004ea4ed     CALL       ManagedArray<int>::contains                      int contains(ManagedArray<int> * this, int * 
    //         004ea4f2     CMP        EAX,0x1
    //         004ea4f5     JZ         LAB_004ea51e
    //         004ea4f7     MOV        this,dword ptr [ESI + 0xc]
    //         004ea4fa     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ea4fd     DEC        this
    //         004ea4fe     CMP        EAX,this
    //         004ea500     JLE        LAB_004ea50b
    //         004ea502     INC        EAX
    //         004ea503     MOV        this,ESI
    //         004ea505     PUSH       EAX
    //         004ea506     CALL       ManagedArray<int>::resize                        int resize(ManagedArray<int> * this, int para
    //                               LAB_004ea50b                                                 XREF[1]:     004ea500(j)  
    //         004ea50b     MOV        EDX,dword ptr [ESI + 0x4]
    //         004ea50e     MOV        EAX,dword ptr [ESI]
    //         004ea510     MOV        this,dword ptr [ESP + param_1]
    //         004ea514     MOV        dword ptr [EAX + EDX*0x4],this
    //         004ea517     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ea51a     INC        EAX
    //         004ea51b     MOV        dword ptr [ESI + 0x4],EAX
    //                               LAB_004ea51e                                                 XREF[1]:     004ea4f5(j)  
    //                              taistrmd.cpp:1561 (64)
    //         004ea51e     LEA        EDX=>param_1,[ESP + 0x14]
    //         004ea522     MOV        this,ESI
    //         004ea524     PUSH       EDX
    //         004ea525     MOV        dword ptr [ESP + param_1],0x17
    //         004ea52d     CALL       ManagedArray<int>::contains                      int contains(ManagedArray<int> * this, int * 
    //         004ea532     CMP        EAX,0x1
    //         004ea535     JZ         LAB_004ea55e
    //         004ea537     MOV        this,dword ptr [ESI + 0xc]
    //         004ea53a     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ea53d     DEC        this
    //         004ea53e     CMP        EAX,this
    //         004ea540     JLE        LAB_004ea54b
    //         004ea542     INC        EAX
    //         004ea543     MOV        this,ESI
    //         004ea545     PUSH       EAX
    //         004ea546     CALL       ManagedArray<int>::resize                        int resize(ManagedArray<int> * this, int para
    //                               LAB_004ea54b                                                 XREF[1]:     004ea540(j)  
    //         004ea54b     MOV        EDX,dword ptr [ESI + 0x4]
    //         004ea54e     MOV        EAX,dword ptr [ESI]
    //         004ea550     MOV        this,dword ptr [ESP + param_1]
    //         004ea554     MOV        dword ptr [EAX + EDX*0x4],this
    //         004ea557     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ea55a     INC        EAX
    //         004ea55b     MOV        dword ptr [ESI + 0x4],EAX
    //                               LAB_004ea55e                                                 XREF[1]:     004ea535(j)  
    //                              taistrmd.cpp:1562 (64)
    //         004ea55e     LEA        EDX=>param_1,[ESP + 0x14]
    //         004ea562     MOV        this,ESI
    //         004ea564     PUSH       EDX
    //         004ea565     MOV        dword ptr [ESP + param_1],0x18
    //         004ea56d     CALL       ManagedArray<int>::contains                      int contains(ManagedArray<int> * this, int * 
    //         004ea572     CMP        EAX,0x1
    //         004ea575     JZ         LAB_004ea59e
    //         004ea577     MOV        this,dword ptr [ESI + 0xc]
    //         004ea57a     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ea57d     DEC        this
    //         004ea57e     CMP        EAX,this
    //         004ea580     JLE        LAB_004ea58b
    //         004ea582     INC        EAX
    //         004ea583     MOV        this,ESI
    //         004ea585     PUSH       EAX
    //         004ea586     CALL       ManagedArray<int>::resize                        int resize(ManagedArray<int> * this, int para
    //                               LAB_004ea58b                                                 XREF[1]:     004ea580(j)  
    //         004ea58b     MOV        EDX,dword ptr [ESI + 0x4]
    //         004ea58e     MOV        EAX,dword ptr [ESI]
    //         004ea590     MOV        this,dword ptr [ESP + param_1]
    //         004ea594     MOV        dword ptr [EAX + EDX*0x4],this
    //         004ea597     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ea59a     INC        EAX
    //         004ea59b     MOV        dword ptr [ESI + 0x4],EAX
    //                               LAB_004ea59e                                                 XREF[1]:     004ea575(j)  
    //                              taistrmd.cpp:1563 (64)
    //         004ea59e     LEA        EDX=>param_1,[ESP + 0x14]
    //         004ea5a2     MOV        this,ESI
    //         004ea5a4     PUSH       EDX
    //         004ea5a5     MOV        dword ptr [ESP + param_1],0x19
    //         004ea5ad     CALL       ManagedArray<int>::contains                      int contains(ManagedArray<int> * this, int * 
    //         004ea5b2     CMP        EAX,0x1
    //         004ea5b5     JZ         LAB_004ea5de
    //         004ea5b7     MOV        this,dword ptr [ESI + 0xc]
    //         004ea5ba     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ea5bd     DEC        this
    //         004ea5be     CMP        EAX,this
    //         004ea5c0     JLE        LAB_004ea5cb
    //         004ea5c2     INC        EAX
    //         004ea5c3     MOV        this,ESI
    //         004ea5c5     PUSH       EAX
    //         004ea5c6     CALL       ManagedArray<int>::resize                        int resize(ManagedArray<int> * this, int para
    //                               LAB_004ea5cb                                                 XREF[1]:     004ea5c0(j)  
    //         004ea5cb     MOV        EDX,dword ptr [ESI + 0x4]
    //         004ea5ce     MOV        EAX,dword ptr [ESI]
    //         004ea5d0     MOV        this,dword ptr [ESP + param_1]
    //         004ea5d4     MOV        dword ptr [EAX + EDX*0x4],this
    //         004ea5d7     MOV        EAX,dword ptr [ESI + 0x4]
    //         004ea5da     INC        EAX
    //         004ea5db     MOV        dword ptr [ESI + 0x4],EAX
    //                               LAB_004ea5de                                                 XREF[1]:     004ea5b5(j)  
    //                              taistrmd.cpp:1564 (9)
    //         004ea5de     PUSH       0x1a
    //         004ea5e0     MOV        this,ESI
    //         004ea5e2     CALL       ManagedArray<int>::add                           int add(ManagedArray<int> * this, int param_1)
    //                              taistrmd.cpp:1565 (9)
    //         004ea5e7     PUSH       0x1b
    //         004ea5e9     MOV        this,ESI
    //         004ea5eb     CALL       ManagedArray<int>::add                           int add(ManagedArray<int> * this, int param_1)
    //                              taistrmd.cpp:1566 (9)
    //         004ea5f0     PUSH       0x1c
    //         004ea5f2     MOV        this,ESI
    //         004ea5f4     CALL       ManagedArray<int>::add                           int add(ManagedArray<int> * this, int param_1)
    //                              taistrmd.cpp:1567 (9)
    //         004ea5f9     PUSH       0x1d
    //         004ea5fb     MOV        this,ESI
    //         004ea5fd     CALL       ManagedArray<int>::add                           int add(ManagedArray<int> * this, int param_1)
    //                              taistrmd.cpp:1568 (9)
    //         004ea602     PUSH       0x1e
    //         004ea604     MOV        this,ESI
    //         004ea606     CALL       ManagedArray<int>::add                           int add(ManagedArray<int> * this, int param_1)
    //                              taistrmd.cpp:1569 (9)
    //         004ea60b     PUSH       0x1f
    //         004ea60d     MOV        this,ESI
    //         004ea60f     CALL       ManagedArray<int>::add                           int add(ManagedArray<int> * this, int param_1)
    //                              taistrmd.cpp:1570 (9)
    //         004ea614     PUSH       0x20
    //         004ea616     MOV        this,ESI
    //         004ea618     CALL       ManagedArray<int>::add                           int add(ManagedArray<int> * this, int param_1)
    //                              taistrmd.cpp:1571 (9)
    //         004ea61d     PUSH       0x21
    //         004ea61f     MOV        this,ESI
    //         004ea621     CALL       ManagedArray<int>::add                           int add(ManagedArray<int> * this, int param_1)
    //                              taistrmd.cpp:1572 (9)
    //         004ea626     PUSH       0x22
    //         004ea628     MOV        this,ESI
    //         004ea62a     CALL       ManagedArray<int>::add                           int add(ManagedArray<int> * this, int param_1)
    //                              taistrmd.cpp:1573 (9)
    //         004ea62f     PUSH       0x23
    //         004ea631     MOV        this,ESI
    //         004ea633     CALL       ManagedArray<int>::add                           int add(ManagedArray<int> * this, int param_1)
    //                              taistrmd.cpp:1574 (9)
    //         004ea638     PUSH       0x24
    //         004ea63a     MOV        this,ESI
    //         004ea63c     CALL       ManagedArray<int>::add                           int add(ManagedArray<int> * this, int param_1)
    //                              taistrmd.cpp:1575 (9)
    //         004ea641     PUSH       0x25
    //         004ea643     MOV        this,ESI
    //         004ea645     CALL       ManagedArray<int>::add                           int add(ManagedArray<int> * this, int param_1)
    //                              taistrmd.cpp:1576 (9)
    //         004ea64a     PUSH       0x26
    //         004ea64c     MOV        this,ESI
    //         004ea64e     CALL       ManagedArray<int>::add                           int add(ManagedArray<int> * this, int param_1)
    //                              taistrmd.cpp:1577 (9)
    //         004ea653     PUSH       0x27
    //         004ea655     MOV        this,ESI
    //         004ea657     CALL       ManagedArray<int>::add                           int add(ManagedArray<int> * this, int param_1)
    //                              taistrmd.cpp:1578 (9)
    //         004ea65c     PUSH       0x28
    //         004ea65e     MOV        this,ESI
    //         004ea660     CALL       ManagedArray<int>::add                           int add(ManagedArray<int> * this, int param_1)
    //                              taistrmd.cpp:1579 (9)
    //         004ea665     PUSH       0x29
    //         004ea667     MOV        this,ESI
    //         004ea669     CALL       ManagedArray<int>::add                           int add(ManagedArray<int> * this, int param_1)
    //                              taistrmd.cpp:1580 (9)
    //         004ea66e     PUSH       0x2a
    //         004ea670     MOV        this,ESI
    //         004ea672     CALL       ManagedArray<int>::add                           int add(ManagedArray<int> * this, int param_1)
    //                              taistrmd.cpp:1581 (9)
    //         004ea677     PUSH       0x2b
    //         004ea679     MOV        this,ESI
    //         004ea67b     CALL       ManagedArray<int>::add                           int add(ManagedArray<int> * this, int param_1)
    //                              taistrmd.cpp:1582 (9)
    //         004ea680     PUSH       0x2c
    //         004ea682     MOV        this,ESI
    //         004ea684     CALL       ManagedArray<int>::add                           int add(ManagedArray<int> * this, int param_1)
    //                              taistrmd.cpp:1583 (9)
    //         004ea689     PUSH       0x2d
    //         004ea68b     MOV        this,ESI
    //         004ea68d     CALL       ManagedArray<int>::add                           int add(ManagedArray<int> * this, int param_1)
    //                              taistrmd.cpp:1584 (9)
    //         004ea692     PUSH       0x2e
    //         004ea694     MOV        this,ESI
    //         004ea696     CALL       ManagedArray<int>::add                           int add(ManagedArray<int> * this, int param_1)
    //                              taistrmd.cpp:1585 (9)
    //         004ea69b     PUSH       0x2f
    //         004ea69d     MOV        this,ESI
    //         004ea69f     CALL       ManagedArray<int>::add                           int add(ManagedArray<int> * this, int param_1)
    //                              taistrmd.cpp:1586 (9)
    //         004ea6a4     PUSH       0x30
    //         004ea6a6     MOV        this,ESI
    //         004ea6a8     CALL       ManagedArray<int>::add                           int add(ManagedArray<int> * this, int param_1)
    //                              taistrmd.cpp:1587 (9)
    //         004ea6ad     PUSH       0x31
    //         004ea6af     MOV        this,ESI
    //         004ea6b1     CALL       ManagedArray<int>::add                           int add(ManagedArray<int> * this, int param_1)
    //                              taistrmd.cpp:1598 (12)
    //         004ea6b6     CMP        dword ptr [EBX + 0x23c],EDI
    //         004ea6bc     JLE        LAB_004ea748
    //                              taistrmd.cpp:1600 (42)
    //         004ea6c2     LEA        EBP,[EBX + 0x268]
    //                               LAB_004ea6c8                                                 XREF[1]:     004ea746(j)  
    //         004ea6c8     PUSH       EDI
    //         004ea6c9     MOV        this,ESI
    //         004ea6cb     CALL       ManagedArray<int>::operator[]                    int * operator[](ManagedArray<int> * this, in
    //         004ea6d0     MOV        EDX,dword ptr [EAX]
    //         004ea6d2     MOV        EAX,dword ptr [EBX + 0xf0]
    //         004ea6d8     PUSH       EDX
    //         004ea6d9     MOV        this,dword ptr [EAX + 0x1256c]
    //         004ea6df     PUSH       this
    //         004ea6e0     MOV        this,EBP
    //         004ea6e2     CALL       VictoryConditionRuleSystem::evaluateAsNonInPro   int evaluateAsNonInProgress(VictoryConditionR
    //         004ea6e7     CMP        EAX,-0x2
    //         004ea6ea     JNZ        LAB_004ea73d
    //                              taistrmd.cpp:1602 (41)
    //         004ea6ec     PUSH       EDI
    //         004ea6ed     MOV        this,ESI
    //         004ea6ef     CALL       ManagedArray<int>::operator[]                    int * operator[](ManagedArray<int> * this, in
    //         004ea6f4     MOV        EDX,dword ptr [EAX]
    //         004ea6f6     MOV        this,dword ptr [EBX + 0xf0]
    //         004ea6fc     MOV        EAX,dword ptr [EBX + 0xf4]
    //         004ea702     PUSH       EDX
    //         004ea703     MOV        EDX,dword ptr [this->_padding_ + 0x1256c]
    //         004ea709     PUSH       EAX
    //         004ea70a     PUSH       EDX
    //         004ea70b     MOV        this,EBP
    //         004ea70d     CALL       VictoryConditionRuleSystem::execute              int execute(VictoryConditionRuleSystem * this
    //         004ea712     CMP        EAX,0x1
    //                              taistrmd.cpp:1603 (19)
    //         004ea715     PUSH       EDI
    //         004ea716     MOV        this,ESI
    //         004ea718     JNZ        LAB_004ea72a
    //         004ea71a     CALL       ManagedArray<int>::operator[]                    int * operator[](ManagedArray<int> * this, in
    //         004ea71f     MOV        EAX,dword ptr [EAX]
    //         004ea721     LEA        this,[EBX + 0x248]
    //         004ea727     PUSH       EAX
    //                              taistrmd.cpp:1604 (2)
    //         004ea728     JMP        LAB_004ea738
    //                               LAB_004ea72a                                                 XREF[1]:     004ea718(j)  
    //                              taistrmd.cpp:1605 (19)
    //         004ea72a     CALL       ManagedArray<int>::operator[]                    int * operator[](ManagedArray<int> * this, in
    //         004ea72f     MOV        this,dword ptr [EAX]
    //         004ea731     PUSH       this
    //         004ea732     LEA        this,[EBX + 0x258]
    //                               LAB_004ea738                                                 XREF[1]:     004ea728(j)  
    //         004ea738     CALL       ManagedArray<int>::add                           int add(ManagedArray<int> * this, int param_1)
    //                               LAB_004ea73d                                                 XREF[1]:     004ea6ea(j)  
    //                              taistrmd.cpp:1598 (11)
    //         004ea73d     MOV        EAX,dword ptr [EBX + 0x23c]
    //         004ea743     INC        EDI
    //         004ea744     CMP        EDI,EAX
    //         004ea746     JL         LAB_004ea6c8
    //                               LAB_004ea748                                                 XREF[1]:     004ea6bc(j)  
    //                              taistrmd.cpp:1608 (7)
    //         004ea748     POP        EDI
    //         004ea749     POP        ESI
    //         004ea74a     POP        EBP
    //         004ea74b     POP        EBX
    //         004ea74c     RET        0x4
}

// Offset: 0x004EA7C0
int isRuleExecuting(TribeStrategyAIModule* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TribeStrategyAIModule::isRuleExecuting(int)                                    *
    //                              *********************************************************************************************************
    //                              int __thiscall isRuleExecuting(TribeStrategyAIModule * this, int par
    //              int               EAX:4          <RETURN>
    //              TribeStrategyA    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004ea7d5(R)  
    //                               ?isRuleExecuting@TribeStrategyAIModule@@QAEHH@Z
    //                               TribeStrategyAIModule::isRuleExecuting
    //                              taistrmd.cpp:1613 (45)
    //         004ea7c0     MOV        EDX,dword ptr [ECX + this+0x24c]
    //         004ea7c6     PUSH       EBX
    //         004ea7c7     XOR        EAX,EAX
    //         004ea7c9     PUSH       ESI
    //         004ea7ca     PUSH       EDI
    //         004ea7cb     TEST       EDX,EDX
    //         004ea7cd     JLE        LAB_004ea800
    //         004ea7cf     MOV        EDI,dword ptr [ECX + this+0x254]
    //         004ea7d5     MOV        ESI,dword ptr [ESP + param_1]
    //                               LAB_004ea7d9                                                 XREF[1]:     004ea7eb(j)  
    //         004ea7d9     CMP        EAX,EDI
    //         004ea7db     JGE        LAB_004ea800
    //         004ea7dd     MOV        EBX,dword ptr [ECX + this->executingRules.value]
    //         004ea7e3     CMP        dword ptr [EBX + EAX*0x4],ESI
    //         004ea7e6     JZ         LAB_004ea7f5
    //         004ea7e8     INC        EAX
    //         004ea7e9     CMP        EAX,EDX
    //         004ea7eb     JL         LAB_004ea7d9
    //                              taistrmd.cpp:1616 (2)
    //         004ea7ed     XOR        EAX,EAX
    //                              taistrmd.cpp:1617 (6)
    //         004ea7ef     POP        EDI
    //         004ea7f0     POP        ESI
    //         004ea7f1     POP        EBX
    //         004ea7f2     RET        0x4
    //                               LAB_004ea7f5                                                 XREF[1]:     004ea7e6(j)  
    //                              taistrmd.cpp:1615 (5)
    //         004ea7f5     MOV        EAX,0x1
    //                              taistrmd.cpp:1617 (14)
    //         004ea7fa     POP        EDI
    //         004ea7fb     POP        ESI
    //         004ea7fc     POP        EBX
    //         004ea7fd     RET        0x4
    //                               LAB_004ea800                                                 XREF[2]:     004ea7cd(j), 004ea7db(j)  
    //         004ea800     POP        EDI
    //         004ea801     POP        ESI
    //         004ea802     XOR        EAX,EAX
    //         004ea804     POP        EBX
    //         004ea805     RET        0x4
}

// Offset: 0x004EA810
int isRuleIdle(TribeStrategyAIModule* this_, int param_2) {
    // --- Ghidra listing dump ---
    //                              *********************************************************************************************************
    //                              * public: int __thiscall TribeStrategyAIModule::isRuleIdle(int)                                         *
    //                              *********************************************************************************************************
    //                              int __thiscall isRuleIdle(TribeStrategyAIModule * this, int param_1)
    //              int               EAX:4          <RETURN>
    //              TribeStrategyA    ECX:4 (auto)   this
    //              int               Stack[0x4]:4   param_1                   XREF[1]:     004ea825(R)  
    //                               ?isRuleIdle@TribeStrategyAIModule@@QAEHH@Z
    //                               TribeStrategyAIModule::isRuleIdle
    //                              taistrmd.cpp:1622 (45)
    //         004ea810     MOV        EDX,dword ptr [ECX + this+0x25c]
    //         004ea816     PUSH       EBX
    //         004ea817     XOR        EAX,EAX
    //         004ea819     PUSH       ESI
    //         004ea81a     PUSH       EDI
    //         004ea81b     TEST       EDX,EDX
    //         004ea81d     JLE        LAB_004ea850
    //         004ea81f     MOV        EDI,dword ptr [ECX + this+0x264]
    //         004ea825     MOV        ESI,dword ptr [ESP + param_1]
    //                               LAB_004ea829                                                 XREF[1]:     004ea83b(j)  
    //         004ea829     CMP        EAX,EDI
    //         004ea82b     JGE        LAB_004ea850
    //         004ea82d     MOV        EBX,dword ptr [ECX + this->idleRules.value]
    //         004ea833     CMP        dword ptr [EBX + EAX*0x4],ESI
    //         004ea836     JZ         LAB_004ea845
    //         004ea838     INC        EAX
    //         004ea839     CMP        EAX,EDX
    //         004ea83b     JL         LAB_004ea829
    //                              taistrmd.cpp:1625 (2)
    //         004ea83d     XOR        EAX,EAX
    //                              taistrmd.cpp:1626 (6)
    //         004ea83f     POP        EDI
    //         004ea840     POP        ESI
    //         004ea841     POP        EBX
    //         004ea842     RET        0x4
    //                               LAB_004ea845                                                 XREF[1]:     004ea836(j)  
    //                              taistrmd.cpp:1624 (5)
    //         004ea845     MOV        EAX,0x1
    //                              taistrmd.cpp:1626 (14)
    //         004ea84a     POP        EDI
    //         004ea84b     POP        ESI
    //         004ea84c     POP        EBX
    //         004ea84d     RET        0x4
    //                               LAB_004ea850                                                 XREF[2]:     004ea81d(j), 004ea82b(j)  
    //         004ea850     POP        EDI
    //         004ea851     POP        ESI
    //         004ea852     XOR        EAX,EAX
    //         004ea854     POP        EBX
    //         004ea855     RET        0x4
}


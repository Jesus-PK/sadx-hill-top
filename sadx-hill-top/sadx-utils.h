#pragma once

#define TASKWK_PLAYERID(a) a->counter.b[0]
#define TASKWK_CHARID(a) a->counter.b[1]

static constexpr int MaxPlayers = 4;

enum ObjectFlags {
    ObjFlag_StopDynCol = 0x1,
    ObjFlag_Held       = 0x1000
};

enum INITMODEMD : Sint8
{
    IM_MWK = 0x1,
    IM_TWK = 0x2,
    IM_FWK = 0x4,
    IM_AWK = 0x8
};

struct Color3 {
    unsigned int c1, c2, c3;
};

typedef void(__cdecl* VoidFuncPtr)(void);

FunctionPointer(void, ReleaseModule, (unsigned int u32ModuleType), 0x4228F0);
DataPointer(VoidFuncPtr, ___epilogfunc, 0x3B291B4);
FunctionPointer(void, RedMountain_SetViewData_Clip, (int clipLevel), 0x6007E0);
VoidFunc(RedMountain_SetViewData, 0x600730);
DataArray(Color3, BackColorList, 0x90BFE8, 43);
FunctionPointer(void, KillPlayer, (uint8_t ID), 0x440CD0);
VoidFunc(EnableTimeThing, 0x426030);
FunctionPointer(void, PlayVoiceCheckSetting, (int voice), 0x571990);
DataPointer(ObjectMaster*, Egg1ExplosionTask, 0x3C6C940);
DataPointer(float, BossHealth, 0x3C58158);
FunctionPointer(void, SetCameraBossStuff, (EntityData1* data, float y, float x, int rot), 0x4647C0);
ObjectFunc(ObjectCrash, 0x5A95B0); // position is position, scale is direction, object is the model
FastcallFunctionPointer(void, DrawChunkModel_, (Sint32* a1, Sint16* a2), 0x7917F0);

// Symbols
TaskFunc(EnemyMountainE104_execTgt, 0x605A90); // local name: execTgt
TaskFunc(EnemyMountainE104_dispTgt, 0x6056E0); // local name: dispTgt
TaskFunc(EnemyMountainE104_destTgt, 0x605650); // local name: destTgt
DataArray(NJS_POINT3, pCamTgtLinePos, 0x24C8D00, 5);
FunctionPointer(void, StaticShadow, (taskwk* twp, float ypos), 0x49ED70);
FunctionPointer(float, Shadow, (taskwk* twp, float scl), 0x49EE30);
FunctionPointer(float, _DrawShadow, (Angle3* ang, NJS_POINT3* pos, float scl), 0x49EF30);
FunctionPointer(float, ShadowWithAng, (taskwk* twp, float scl, Angle3* ang), 0x49EFD0);
FunctionPointer(void, SetFreeCameraMode, (Sint32 mode), 0x4348A0); // Set current camera mode (script)

enum class EVTSTATES : int {
    Init,
    Main,
    Free
};

static inline void SetObjectStatusNotHeld(task* tp)
{
    tp->ocp->ssCondition &= ~0x4000u;
}

enum AnimDataProperties {
    AnimProp_NoAnimation,
    AnimProp_FirstFrame,
    AnimProp_Skip,
    AnimProp_Loop,
    AnimProp_OnceT,
    AnimProp_Once,
    AnimProp_ReverseT,
    AnimProp_Reverse,
    AnimProp_OnceCut,
    AnimProp_Input1,
    AnimProp_Input2,
    AnimProp_Input3,
    AnimProp_Custom
};
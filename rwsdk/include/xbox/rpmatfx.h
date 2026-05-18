
#ifndef RPMATFX_H
#define RPMATFX_H

/*===========================================================================*
 *--- Include files ---------------------------------------------------------*
 *===========================================================================*/

#include "rwcore.h"
#include "rpworld.h"

/*---- start: ./matfx.h----*/

#ifndef RPMATFX_MATFX_H
#define RPMATFX_MATFX_H


/**
 * \defgroup rpmatfx RpMatFX
 * \ingroup rpplugin
 *
 * Material Effects Plugin for RenderWare Graphics.
 */

/*===========================================================================*
 *--- Global Types ----------------------------------------------------------*
 *===========================================================================*/

/**
 * \ingroup rpmatfx
 * RpMatFXMaterialFlags, this type represents the different types of
 * material effects that can be used on a material. The effects are
 * initialized with \ref RpMatFXMaterialSetEffects:
 */
enum RpMatFXMaterialFlags
{
    rpMATFXEFFECTNULL       = 0,
    rpMATFXEFFECTBUMPMAP    = 1, /**<Bump mapping                 */
    rpMATFXEFFECTENVMAP     = 2, /**<Environment mapping          */
    rpMATFXEFFECTBUMPENVMAP = 3, /**<Bump and environment mapping */
    rpMATFXEFFECTDUAL       = 4, /**<Dual pass                    */

    rpMATFXEFFECTMAX,
    rpMATFXNUMEFFECTS       = rpMATFXEFFECTMAX - 1,

    rpMATFXFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RpMatFXMaterialFlags  RpMatFXMaterialFlags;


/*===========================================================================*
 *--- Plugin API Functions --------------------------------------------------*
 *===========================================================================*/

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/*--- Plugin functions ------------------------------------------------------*/
extern RwBool
RpMatFXPluginAttach( void );

/*--- Setup functions -------------------------------------------------------*/
extern RpAtomic *
RpMatFXAtomicEnableEffects( RpAtomic *atomic );

extern RwBool
RpMatFXAtomicQueryEffects( RpAtomic *atomic );

extern RpWorldSector *
RpMatFXWorldSectorEnableEffects( RpWorldSector *worldSector );

extern RwBool
RpMatFXWorldSectorQueryEffects( RpWorldSector *worldSector );

extern RpMaterial *
RpMatFXMaterialSetEffects( RpMaterial *material,
                           RpMatFXMaterialFlags flags );


/*--- Setup Effects ---------------------------------------------------------*/
extern RpMaterial *
RpMatFXMaterialSetupBumpMap( RpMaterial *material,
                             RwTexture *texture,
                             RwFrame *frame,
                             RwReal coef );

extern RpMaterial *
RpMatFXMaterialSetupEnvMap( RpMaterial *material,
                            RwTexture *texture,
                            RwFrame *frame,
                            RwBool useFrameBufferAlpha,
                            RwReal coef );

extern RpMaterial *
RpMatFXMaterialSetupDualTexture( RpMaterial *material,
                                 RwTexture *texture,
                                 RwBlendFunction srcBlendMode,
                                 RwBlendFunction dstBlendMode );

/*--- Tinker with effects ---------------------------------------------------*/
extern RpMatFXMaterialFlags
RpMatFXMaterialGetEffects( const RpMaterial *material );

/*--- Bump Map --------------------------------------------------------------*/
extern RpMaterial *
RpMatFXMaterialSetBumpMapTexture( RpMaterial *material,
                                  RwTexture *texture );

extern RpMaterial *
RpMatFXMaterialSetBumpMapFrame( RpMaterial *material,
                                RwFrame *frame );

extern RpMaterial *
RpMatFXMaterialSetBumpMapCoefficient( RpMaterial *material,
                                      RwReal coef );
extern RwTexture *
RpMatFXMaterialGetBumpMapTexture( const RpMaterial *material );

extern RwTexture *
RpMatFXMaterialGetBumpMapBumpedTexture( const RpMaterial *material );

extern RwFrame *
RpMatFXMaterialGetBumpMapFrame( const RpMaterial *material );

extern RwReal
RpMatFXMaterialGetBumpMapCoefficient( const RpMaterial *material );

/*--- Env Map ---------------------------------------------------------------*/
extern RpMaterial *
RpMatFXMaterialSetEnvMapTexture( RpMaterial *material,
                                 RwTexture *texture );

extern RpMaterial *
RpMatFXMaterialSetEnvMapFrame( RpMaterial *material,
                               RwFrame *frame );

extern RpMaterial *
RpMatFXMaterialSetEnvMapFrameBufferAlpha( RpMaterial *material,
                                          RwBool useFrameBufferAlpha );

extern RpMaterial *
RpMatFXMaterialSetEnvMapCoefficient( RpMaterial *material,
                                     RwReal coef );

extern RwTexture *
RpMatFXMaterialGetEnvMapTexture( const RpMaterial *material );

extern RwFrame *
RpMatFXMaterialGetEnvMapFrame( const RpMaterial *material );

extern RwBool
RpMatFXMaterialGetEnvMapFrameBufferAlpha( const RpMaterial *material );

extern RwReal
RpMatFXMaterialGetEnvMapCoefficient( const RpMaterial *material );

/*--- Dual Pass -------------------------------------------------------------*/
extern RpMaterial *
RpMatFXMaterialSetDualTexture( RpMaterial *material,
                               RwTexture *texture );

extern RpMaterial *
RpMatFXMaterialSetDualBlendModes( RpMaterial *material,
                                  RwBlendFunction srcBlendMode,
                                  RwBlendFunction dstBlendMode );

extern RwTexture *
RpMatFXMaterialGetDualTexture( const RpMaterial *material );

extern const RpMaterial *
RpMatFXMaterialGetDualBlendModes( const RpMaterial *material,
                                  RwBlendFunction *srcBlendMode,
                                  RwBlendFunction *dstBlendMode );
#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* RPMATFX_MATFX_H */

/*---- end: ./matfx.h----*/

/*---- start: c:/daily/rwsdk/plugin/matfx/xbox/matfxplatform.h----*/

/*---- start: ./multiTexEffect.h----*/

#ifndef RPMATFX_MULTITEXEFFECT_H
#define RPMATFX_MULTITEXEFFECT_H


/******************************************************************************
 *  Includes
 */
#include "rwcore.h"
#include "rpworld.h"

/******************************************************************************
 *  Defines
 */
#define rpMTEFFECTNAMELENGTH      32

/******************************************************************************
 *  Types
 */


/**
 * \ingroup rpmultitex
 * \struct RpMTEffect
 * RpMTEffect is an opaque type. See the RpMTEffect API.
 */
typedef struct RpMTEffect RpMTEffect;

/**
 * \ingroup rpmultitex
 * \struct RpMTEffectDict
 * RpMTEffectDict is an opaque type.
 *
 * \see RpMTEffectDictCreate
 * \see RpMTEffectDictDestroy
 * \see RpMTEffectDictGetCurrent
 * \see RpMTEffectDictSetCurrent
 * \see RpMTEffectDictAddEffect
 * \see RpMTEffectDictFindNamedEffect
 * \see RpMTEffectDictStreamRead
 */
typedef struct RpMTEffectDict RpMTEffectDict;

/**
 * \ingroup rpmultitex
 * \typedef RpMTEffectCallBack
 * RpMTEffectCallBack is the callback type used with
 * \ref RpMTEffectDictForAllEffects.
 *
 * \param effect    Pointer to the multitexture effect.
 * \param data      Pointer to used data.
 *
 * \return Pointer to the effect, or NULL for early out.
 */
typedef RpMTEffect *(*RpMTEffectCallBack)(RpMTEffect *effect, void *data);

/**
 * \ingroup rpmultitex
 * \typedef RpMTEffectDictCallBack
 * RpMTEffectDictCallBack is the callback type used with
 * \ref RpMTEffectDictForAllDictionaries.
 *
 * \param effect    Pointer to the multitexture effect dictionary.
 * \param data      Pointer to used data.
 *
 * \return Pointer to the effect dictionary, or NULL for early out.
 */
typedef RpMTEffectDict *(*RpMTEffectDictCallBack)(
                            RpMTEffectDict *dict, void *data);


#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/*--- MultiTexture Effect Dictionary Functions ------------------------------*/

extern RpMTEffectDict *
RpMTEffectDictCreate(void);

extern void
RpMTEffectDictDestroy(RpMTEffectDict *dict);

extern RpMTEffectDict *
RpMTEffectDictAddEffect(RpMTEffectDict *dict, RpMTEffect *effect);

extern RpMTEffect *
RpMTEffectDictRemoveEffect(RpMTEffect *effect);

extern RpMTEffect *
RpMTEffectDictFindNamedEffect(const RpMTEffectDict *dict,
                              const RwChar *name);

extern RpMTEffectDict *
RpMTEffectDictSetCurrent(RpMTEffectDict *dict);

extern RpMTEffectDict *
RpMTEffectDictGetCurrent(void);

extern RwUInt32
RpMTEffectDictStreamGetSize(const RpMTEffectDict *dict);

extern const RpMTEffectDict *
RpMTEffectDictStreamWrite(const RpMTEffectDict *dict, RwStream *stream);

extern RpMTEffectDict *
RpMTEffectDictStreamRead(RwStream *stream);

extern RwBool
RpMTEffectDictForAllDictionaries(RpMTEffectDictCallBack callBack, void *data);

extern const RpMTEffectDict *
RpMTEffectDictForAllEffects(const RpMTEffectDict *dict,
                            RpMTEffectCallBack    callBack,
                            void                 *data);

/*--- MultiTexture Effect Functions -----------------------------------------*/

extern const RwChar *
RpMTEffectSetPath(const RwChar *path);

extern RwChar *
RpMTEffectGetPath(void);

extern RpMTEffect *
RpMTEffectCreateDummy(void);

extern void
RpMTEffectDestroy(RpMTEffect *effect);

extern RwUInt32
RpMTEffectStreamGetSize(const RpMTEffect *effect);

extern const RpMTEffect *
RpMTEffectStreamWrite(const RpMTEffect *effect, RwStream *stream);

extern RpMTEffect *
RpMTEffectStreamRead(RwStream *stream);

extern RpMTEffect *
RpMTEffectFind(RwChar *name);

extern const RpMTEffect *
RpMTEffectWrite(const RpMTEffect *effect);

extern RpMTEffect *
RpMTEffectSetName(RpMTEffect *effect, RwChar *name);

extern RwChar *
RpMTEffectGetName(RpMTEffect *effect);

extern RpMTEffect *
RpMTEffectAddRef(RpMTEffect *effect);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* RPMATFX_MULTITEXEFFECT_H */

/*---- end: ./multiTexEffect.h----*/
/*---- start: ./multiTex.h----*/

#ifndef RPMATFX_MULTITEX_H
#define RPMATFX_MULTITEX_H

/**
 * \ingroup rpmultitex
 * \struct RpMultiTexture
 * RpMultiTexture is an opaque type.
 *
 * \see RpMaterialCreateMultiTexture
 * \see RpMaterialGetMultiTexture
 * \see RpMultiTextureSetTexture
 * \see RpMultiTextureGetTexture
 * \see RpMultiTextureSetCoords
 * \see RpMultiTextureGetCoords
 * \see RpMultiTextureSetEffect
 * \see RpMultiTextureGetEffect
 */
typedef struct RpMultiTexture RpMultiTexture;

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/*--- MultiTexture Functions ------------------------------------------------*/

extern RwUInt32
RpMultiTextureGetNumTextures(const RpMultiTexture *multiTexture);

extern RpMultiTexture *
RpMultiTextureSetTexture(RpMultiTexture *multiTexture,
                         RwUInt32        index,
                         RwTexture      *texture);

extern RwTexture *
RpMultiTextureGetTexture(const RpMultiTexture *multiTexture,
                         RwUInt32        index);

extern RpMultiTexture *
RpMultiTextureSetCoords(RpMultiTexture *multiTexture,
                        RwUInt32        index,
                        RwUInt32        texCoordIndex);

extern RwUInt32
RpMultiTextureGetCoords(const RpMultiTexture *multiTexture,
                        RwUInt32        index);

extern RpMultiTexture *
RpMultiTextureSetEffect(RpMultiTexture *multiTexture,
                        RpMTEffect    *effect);

extern RpMTEffect *
RpMultiTextureGetEffect(const RpMultiTexture *multiTexture);


/*--- Material MultiTexture Functions ---------------------------------------*/

extern RpMaterial *
RpMaterialCreateMultiTexture(RpMaterial *material,
                             RwPlatformID platformID,
                             RwUInt32 numTextures);

extern RpMaterial *
RpMaterialDestroyMultiTexture(RpMaterial *material,
                              RwPlatformID platformID);

extern RpMultiTexture *
RpMaterialGetMultiTexture(const RpMaterial *material,
                          RwPlatformID platformID);

extern RwBool
RpMaterialQueryMultiTexturePlatform(RwPlatformID platformID);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* RPMATFX_MULTITEX_H */

/*---- end: ./multiTex.h----*/
/*---- start: c:/daily/rwsdk/plugin/matfx/xbox/multiTexXbox.h----*/

#ifndef RPMATFX_MULTITEXXBOX_H
#define RPMATFX_MULTITEXXBOX_H

/**
 * \defgroup rpmatfxxbox Xbox
 * \ingroup rpmatfx
 *
 * Xbox specific documentation.
 */

/**
 * \defgroup rpmatfxxboxex Xbox Multitexturing
 * \ingroup rpmatfxxbox
 */

/**
 *
 * \ingroup rpmatfxxboxex
 * \page rpxboxmtoverview Xbox Multitexturing overview
 *
 * \par What is Xbox Multitexturing?
 *
 * Xbox Multitexturing allows access to Hardware specific features helping the use
 * of multitexturing and texture coordinates generation.
 *
 */


/**
 * \ingroup rpmatfxxboxex
 * \par Texture Operators
 * The texture operators are used in the \ref RpMatFXXboxStage structure to define
 * how the texture color and alpha channels are combined. They mimick the behaviour
 * of the D3D type D3DTEXTUREOP
 *
 * \li RpD3DTOP_DISABLE  disables stage
 * \li RpD3DTOP_SELECTARG1 selects the first argument
 * \li RpD3DTOP_SELECTARG2 selects the second argument
 * \li RpD3DTOP_MODULATE multiplies the arguments together
 * \li RpD3DTOP_MODULATE2X multiplies the arguments and shifts the result left one bit
 * \li RpD3DTOP_MODULATE4X multiplies the arguments and shifts the result left two bits
 * \li RpD3DTOP_ADD adds the two arguments
 * \li RpD3DTOP_ADDSIGNED adds the arguments with a -0.5 bias, making
 * the effective range -0.5 through 0.5
 * \li RpD3DTOP_ADDSIGNED2X adds the arugments with a -0.5 bias and shifts the result left one bit
 * \li RpD3DTOP_SUBTRACT subtracts the two arguments
 * \li RpD3DTOP_ADDSMOOTH adds the two arguments and then subtracts their products from the result
 * \li RpD3DTOP_BLENDDIFFUSEALPHA linearly blends the interpolated alpha from ech vertex
 * \li RpD3DTOP_BLENDTEXTUREALPHA linearly blends the alpha from this stage's texture
 * \li RpD3DTOP_BLENDFACTORALPHA linearly blends the alpha from the texture factor
 * \li RpD3DTOP_BLENDTEXTUREALPHAPM linearly blends a texture stage that uses a premultiplied alpha
 * \li RpD3DTOP_BLENDCURRENTALPHA linearly blends the alpha from the previous stage
 * \li RpD3DTOP_PREMODULATE modulate this texture stage with the next one
 * \li RpD3DTOP_MODULATEALPHA_ADDCOLOR modulates the color from the second argument using the alpha
 * of the first argument, then add the result to the first argument
 * \li RpD3DTOP_MODULATEINVALPHA_ADDCOLOR similar to RpD3DTOP_MODULATEALPHA_ADDCOLOR, but uses the inverse
 * of the alpha of the first argument
 * \li RpD3DTOP_MODULATECOLOR_ADDALPHA Modulates the arguments, then add the alpha of the first argument
 * \li RpD3DTOP_MODULATEINVCOLOR_ADDALPHA similar to RpD3DTOP_MODULATECOLOR_ADDALPHA, but uses the inverse
 * of the color of the first argument
 * \li RpD3DTOP_DOTPRODUCT3 does a dot product between argument one and two using individual channels
 * as xyz. The result is duplicated in all four channels.
 * \li RpD3DTOP_MULTIPLYADD multiplies arg1 and arg2, and adds arg0
 * \li RpD3DTOP_LERP multiplies arg0 and arg1, then adds a blend of arg0 and arg2
 */
enum RpD3DTEXTUREOP
{
    RpNAD3DTOP                    = 0,

    /* Control */
    RpD3DTOP_DISABLE              = 1,      /* disables stage */
    RpD3DTOP_SELECTARG1           = 2,      /* the default */
    RpD3DTOP_SELECTARG2           = 3,

    /* Modulate */
    RpD3DTOP_MODULATE             = 4,      /* multiply args together */
    RpD3DTOP_MODULATE2X           = 5,      /* multiply and  1 bit */
    RpD3DTOP_MODULATE4X           = 6,      /* multiply and  2 bits */

    /* Add */
    RpD3DTOP_ADD                  =  7,   /* add arguments together */
    RpD3DTOP_ADDSIGNED            =  8,   /* add with -0.5 bias */
    RpD3DTOP_ADDSIGNED2X          =  9,   /* as above but left  1 bit */
    RpD3DTOP_SUBTRACT             = 10,   /* Arg1 - Arg2, with no saturation */
    RpD3DTOP_ADDSMOOTH            = 11,   /* add 2 args, subtract product
                                        // Arg1 + Arg2 - Arg1*Arg2
                                        // = Arg1 + (1-Arg1)*Arg2 */

    /* Linear alpha blend: Arg1*(Alpha) + Arg2*(1-Alpha) */
    RpD3DTOP_BLENDDIFFUSEALPHA    = 12, /* iterated alpha */
    RpD3DTOP_BLENDTEXTUREALPHA    = 14, /* texture alpha */
    RpD3DTOP_BLENDFACTORALPHA     = 15, /* alpha from D3DRENDERSTATE_TEXTUREFACTOR */

    /* Linear alpha blend with pre-multiplied arg1 input: Arg1 + Arg2*(1-Alpha) */
    RpD3DTOP_BLENDTEXTUREALPHAPM  = 16, /* texture alpha */
    RpD3DTOP_BLENDCURRENTALPHA    = 13, /* by alpha of current color */

    /* Specular mapping */
    RpD3DTOP_PREMODULATE            = 17,     /* modulate with next texture before use */
    RpD3DTOP_MODULATEALPHA_ADDCOLOR = 18,     /* Arg1.RGB + Arg1.A*Arg2.RGB */
                                            /* COLOROP only */
    RpD3DTOP_MODULATECOLOR_ADDALPHA = 19,     /* Arg1.RGB*Arg2.RGB + Arg1.A */
                                            /* COLOROP only */
    RpD3DTOP_MODULATEINVALPHA_ADDCOLOR = 20,  /* (1-Arg1.A)*Arg2.RGB + Arg1.RGB */
                                            /* COLOROP only */
    RpD3DTOP_MODULATEINVCOLOR_ADDALPHA = 21,  /* (1-Arg1.RGB)*Arg2.RGB + Arg1.A */
                                            /* COLOROP only */

    /* This can do either diffuse or specular bump mapping with correct input.
       Performs the function (Arg1.R*Arg2.R + Arg1.G*Arg2.G + Arg1.B*Arg2.B)
       where each component has been scaled and offset to make it signed.
       The result is replicated into all four (including alpha) channels.
       This is a valid COLOROP only.*/
    RpD3DTOP_DOTPRODUCT3          = 22,

    /* Triadic ops */
    RpD3DTOP_MULTIPLYADD          = 23, /* Arg0 + Arg1*Arg2 */
    RpD3DTOP_LERP                 = 24, /* (Arg0)*Arg1 + (1-Arg0)*Arg2 */

    /* Bump mapping */
    RpD3DTOP_BUMPENVMAP           = 25, /* per pixel env map perturbation */
    RpD3DTOP_BUMPENVMAPLUMINANCE  = 26, /* with luminance channel */

    RpD3DTOP_MAX                  = 27,
    RpD3DTOP_FORCE_DWORD = 0x7fffffff
};

typedef enum RpD3DTEXTUREOP RpD3DTEXTUREOP;

/**
 * \ingroup rpmatfxxboxex
 * \par Texture arguments
 * The texture arguments are used in the \ref RpMatFXXboxStage to define from wht input the color and
 * alpha fragments are to be taken. They mimick the behaviour of the D3D defines D3DTA_SELECTMASK,
 * D3DTA_DIFFUSE, D3DTA_CURRENT, D3DTA_TEXTURE, D3DTA_TFACTOR, D3DTA_SPECULAR, D3DTA_TEMP,
 * D3DTA_COMPLEMENT and D3DTA_ALPHAREPLICATE
 *
 * \li RpD3DTA_DIFFUSE the texture argument is the diffuse color interpolated from vertex components
 * during Gouraud shading
 * \li RpD3DTA_CURRENT the texture argument is the result of the previous blending stage
 * \li RpD3DTA_TEXTURE the texture argument is the texture set for this stage
 * \li RpD3DTA_TFACTOR the texture argument is the texture factor, as set in
 * the \ref RpMatFXXboxMiscState structure
 * \li RpD3DTA_TEMP the texture argument is the temporary register
 * \li RpD3DTA_SELECTMASK mask value for all arguments, not used when setting texture arguments
 * \li RpD3DTA_COMPLEMENT take 1.0 - x (read modifier)
 * \li RpD3DTA_ALPHAREPLICATE replicates the alpha to the color components (read modifier)
 */
enum RpD3DTEXTUREARG
{
        RpD3DTA_DIFFUSE = 0x00000000,  /* select diffuse color (read only) */
        RpD3DTA_CURRENT = 0x00000001,  /* select stage destination register (read/write) */
        RpD3DTA_TEXTURE = 0x00000002,  /* select texture color (read only) */
        RpD3DTA_TFACTOR = 0x00000003,  /* select RENDERSTATE_TEXTUREFACTOR (read only) */
        RpD3DTA_SPECULAR = 0x00000004,  /* select specular color (read only) */
        RpD3DTA_TEMP = 0x00000005,  /* select temporary register color (read/write) */
        RpD3DTA_SELECTMASK = 0x0000000f,  /* mask for arg selector */
        RpD3DTA_COMPLEMENT = 0x00000010,  /* take 1.0 - x (read modifier) */
        RpD3DTA_ALPHAREPLICATE = 0x00000020  /* replicate alpha to color components (read modifier) */
};

typedef enum rpD3DTEXTUREARG rpD3DTEXTUREARG;


/**
 * \ingroup rpmatfxxboxex
 * \par Texture transform flags
 * The texture transform flags instruct the GPU on how to handle the texture coordinates.
 * They are used in the \ref RpMatFXXboxStage structure. They mimick the behaviour of the
 * D3DTEXTURETRANSFORMFLAGS D3D type
 *
 * \li RpD3DTTFF_DISABLE the texture coordinates are passed directly to the rasterizer
 * \li RpD3DTTFF_COUNT1 the rasteriser should expect 1-D texture coordinates
 * \li RpD3DTTFF_COUNT2 the rasteriser should expect 2-D texture coordinates
 * \li RpD3DTTFF_COUNT3 the rasteriser should expect 3-D texture coordinates
 * \li RpD3DTTFF_COUNT4 the rasteriser should expect 4-D texture coordinates
 * \li RpD3DTTFF_PROJECTED the texture coordinates are all divided by the last element in the texture
 * coordinates before being passed to the rasteriser
 */
enum RpD3DTEXTURETRANSFORMFLAGS
{
    RpD3DTTFF_DISABLE         = 0,    /* texture coordinates are passed directly */
    RpD3DTTFF_COUNT1          = 1,    /* rasterizer should expect 1-D texture coords */
    RpD3DTTFF_COUNT2          = 2,    /* rasterizer should expect 2-D texture coords */
    RpD3DTTFF_COUNT3          = 3,    /* rasterizer should expect 3-D texture coords */
    RpD3DTTFF_COUNT4          = 4,    /* rasterizer should expect 4-D texture coords */
    RpD3DTTFF_PROJECTED       = 256,  /* texcoords to be divided by COUNTth element */
    RpD3DTTFF_FORCE_DWORD     = 0x7fffffff
};
typedef enum rpD3DTEXTURETRANSFORMFLAGS rpD3DTEXTURETRANSFORMFLAGS;

/**
 * \ingroup rpmatfxxboxex
 * RpD3DTSIGN_ASIGNED treats the alpha component as being signed
 */
#define RpD3DTSIGN_ASIGNED           0x10000000

/**
 * \ingroup rpmatfxxboxex
 * RpD3DTSIGN_AUNSIGNED treats the alpha component as being unsigned
 */
#define RpD3DTSIGN_AUNSIGNED         0

/**
 * \ingroup rpmatfxxboxex
 * RpD3DTSIGN_RSIGNED treats the red component as being signed
 */
#define RpD3DTSIGN_RSIGNED           0x20000000

/**
 * \ingroup rpmatfxxboxex
 * RpD3DTSIGN_RUNSIGNED treats the red component as being unsigned
 */
#define RpD3DTSIGN_RUNSIGNED         0

/**
 * \ingroup rpmatfxxboxex
 * RpD3DTSIGN_GSIGNED treats the green component as being signed
 */
#define RpD3DTSIGN_GSIGNED           0x40000000

/**
 * \ingroup rpmatfxxboxex
 * RpD3DTSIGN_GUNSIGNED treats the green component as being unsigned
 */
#define RpD3DTSIGN_GUNSIGNED         0

/**
 * \ingroup rpmatfxxboxex
 * RpD3DTSIGN_BSIGNED treats the blue component as being signed
 */
#define RpD3DTSIGN_BSIGNED           0x80000000

/**
 * \ingroup rpmatfxxboxex
 * RpD3DTSIGN_BUNSIGNED treats the blue component as being unsigned
 */
#define RpD3DTSIGN_BUNSIGNED         0

/**
 * \ingroup rpmatfxxboxex
 * \par Alphakill settings
 * Alphakill is used to control the behaviour of the alpha scissoring. This structure mimicks
 * the behaviour of the D3DTEXTUREALPHAKILL D3D type
 *
 * \li RpD3DTALPHAKILL_DISABLE alphakill is disabled. This is the default behaviour
 * \li RpD3DTALPHAKILL_ENABLE alphakill is enabled. Any pixel with an alpha of 0 won't be drawn.
 */
enum RpD3DTEXTUREALPHAKILL
{
    RpD3DTALPHAKILL_DISABLE       = 0,
    RpD3DTALPHAKILL_ENABLE        = 4,

    RpD3DTALPHAKILL_FORCE_DWORD   = 0x7fffffff /* force 32-bit size enum */
};
typedef enum RpD3DTEXTUREALPHAKILL RpD3DTEXTUREALPHAKILL;


/**
 * \ingroup rpmatfxxboxex
 * RpD3DTSS_TCI_PASSTHRU specifies that the texture coordinates are not altered by the
 * texture coordinates generation part of the GPU
 */
#define RpD3DTSS_TCI_PASSTHRU                             0x00000000

/**
 * \ingroup rpmatfxxboxex
 * RpD3DTSS_TCI_CAMERASPACENORMAL the texture coordinates generation uses the vertex normal
 * transformed to camera space as a source
 */
#define RpD3DTSS_TCI_CAMERASPACENORMAL                    0x00010000

/**
 * \ingroup rpmatfxxboxex
 * RpD3DTSS_TCI_CAMERASPACEPOSITION the texture coordinates generation uses the vertex position
 * transformed to camera space as a source
 */
#define RpD3DTSS_TCI_CAMERASPACEPOSITION                  0x00020000

/**
 * \ingroup rpmatfxxboxex
 * RpD3DTSS_TCI_CAMERASPACEREFLECTIONVECTOR the texture coordinates generation uses the reflection
 * vector transformed to camera space as a source
 */
#define RpD3DTSS_TCI_CAMERASPACEREFLECTIONVECTOR          0x00030000
#define RpD3DTSS_TCI_OBJECT                               0x00040000
#define RpD3DTSS_TCI_SPHERE                               0x00050000

#define RpD3DTSS_TCI_TEXCOORDINDEX_MAX                    8
#define RpD3DTSS_TCI_TEXGEN_MAX                           0x00060000

/**
 * \ingroup rpmatfxxboxex
 * \par Final blend
 * These values are used to override the RenderWare values for blending. They are used in the
 * \ref RpMatFXXboxFinalBlend structure. They mimick the  behaviour of the D3DBLEND D3D type.
 *
 * \li RpD3DBLEND_ZERO Blend factor is (0, 0, 0, 0)
 * \li RpD3DBLEND_ONE Blend factor is (1, 1, 1, 1)
 * \li RpD3DBLEND_SRCCOLOR blend factor is source (R, G, B, A)
 * \li RpD3DBLEND_INVSRCCOLOR blend factor is source (1-R, 1-G, 1-B, 1-A)
 * \li RpD3DBLEND_SRCALPHA blend factor is source (A, A, A, A)
 * \li RpD3DBLEND_INVSRCALPHA blend factor is source (1-A, 1-A, 1-A, 1-A)
 * \li RpD3DBLEND_DESTALPHA blend factor is destination (A, A, A, A)
 * \li RpD3DBLEND_INVDESTALPHA blend factor is destination (1-A, 1-A, 1-A, 1-A)
 * \li RpD3DBLEND_DESTCOLOR blend factor is destination (R, G, B, A)
 * \li RpD3DBLEND_INVDESTCOLOR blend factor is destination (1-R, 1-G, 1-B, 1-A)
 * \li RpD3DBLEND_SRCALPHASAT blend factor is(f, f, f, f), f = min source (A, 1-A)
 * \li RpD3DBLEND_CONSTANTCOLOR the blend factor for each color is a constant
 * \li RpD3DBLEND_INVCONSTANTCOLOR the blend factor for each color is the inverse of the constant
 * \li RpD3DBLEND_CONSTANTALPHA the blend factor for the alpha value is a constant
 * \li RpD3DBLEND_INVCONSTALPHA the blend factor for the alpha value is the inverse of the constant
 */
enum RpD3DBLEND
{
    RpD3DBLEND_ZERO               = 0,
    RpD3DBLEND_ONE                = 1,
    RpD3DBLEND_SRCCOLOR           = 0x300,
    RpD3DBLEND_INVSRCCOLOR        = 0x301,
    RpD3DBLEND_SRCALPHA           = 0x302,
    RpD3DBLEND_INVSRCALPHA        = 0x303,
    RpD3DBLEND_DESTALPHA          = 0x304,
    RpD3DBLEND_INVDESTALPHA       = 0x305,
    RpD3DBLEND_DESTCOLOR          = 0x306,
    RpD3DBLEND_INVDESTCOLOR       = 0x307,
    RpD3DBLEND_SRCALPHASAT        = 0x308,
    RpD3DBLEND_CONSTANTCOLOR      = 0x8001,
    RpD3DBLEND_INVCONSTANTCOLOR   = 0x8002,
    RpD3DBLEND_CONSTANTALPHA      = 0x8003,
    RpD3DBLEND_INVCONSTANTALPHA   = 0x8004,

    RpD3DBLEND_FORCE_DWORD        = 0x7fffffff /* force 32-bit size enum */

};
typedef enum RpD3DBLEND RpD3DBLEND;

/**
 * \ingroup rpmatfxxboxex
 * D3D Matrix
 * This structure is used to specify the matrix used by the texture transform part of the GPU in
 * the \ref RpMatFXXboxStage structure. It mimicks the behaviour of the D3DMATRIX structure in D3D
 */
typedef struct RpD3DMATRIX RpD3DMATRIX;




struct RpD3DMATRIX
{
    RwReal _11, _12, _13, _14;
    RwReal _21, _22, _23, _24;
    RwReal _31, _32, _33, _34;
    RwReal _41, _42, _43, _44;
};
typedef struct RpD3DMATRIX RpD3DMATRIX;

/*
 * Xbox structs
 */

/**
 * \ingroup rpmatfxxboxex
 * \par RpMatFXXboxStage
 * This structure is used to define one stage in the Xbox multitexturing setup. It is used
 * in the \ref RpMatFXXboxMaterial structure. An array of RpMatFXXboxStage is defined in
 * \ref RpMatFXXboxMaterial.
 */
struct RpMatFXXboxStage
{
    RwInt32 colorOp; /**< specifies which operation is to be performed on the color fragments of this
                          stage. Valid values are members of the \ref RpD3DTEXTUREOP enumeration */
    RwInt32 colorArg0; /**< specifies the source for the color argument 0.
                            Valid values are members of the \ref RpD3DTEXTUREARG enumeration. Note that this member is only
                            used in triadic operations, i.e. RpD3DTOP_MULTIPLYADD and RpD3DTOP_LERP */
    RwInt32 colorArg1; /**< specifies the source for the color argument 1. Valid values are members
                            of the \ref RpD3DTEXTUREARG enumeration*/
    RwInt32 colorArg2; /**< specifies the source for the color argument 2. Valid values are members
                            of the \ref RpD3DTEXTUREARG enumeration*/

    RwInt32 alphaOp; /**< specifies with operation is to be performed on the alpha fragment of this stage
                          Valid values are members of the \ref RpD3DTEXTUREOP enumeration */
    RwInt32 alphaArg0; /**< specifies the source for alpha argument 0. Valid values are members of the
                            \ref RpD3DTEXTUREARG enumeration. Note that this member is only used in triadic operations,
                            i.e. RpD3DTOP_MULTIPLYADD and RpD3DTOP_LERP */
    RwInt32 alphaArg1; /**< specifies the source for alpha argument 1. Valid values are members of the
                            \ref RpD3DTEXTUREARG enumeration*/
    RwInt32 alphaArg2; /**< specifies the source for alpha argument 2. Valid values are members of the
                            \ref RpD3DTEXTUREARG enumeration*/
    RwInt32 resultArg; /**< specifies the destination of the color and alpha result of this stage. Valid
                            values are RpD3DTA_CURRENT and RpD3DTA_TEMP. The default value is RpD3DTA_CURRENT*/
    RwInt32 textureTransformFlags; /**< controls the transformation of texture coordinates for this stage.
                                        Valid values are members of the \ref RpD3DTEXTURETRANSFORMFLAGS enumeration.*/

    RwInt32 colorSign; /**< specifies how each color and alpha fragment should be processed (as either signed
                            or unsigned). Valid values are a combination of \ref RpD3DTSIGN_ASIGNED, \ref RpD3DTSIGN_AUNSIGNED,
                            \ref RpD3DTSIGN_RSIGNED, \ref RpD3DTSIGN_RUNSIGNED, \ref RpD3DTSIGN_GSIGNED, \ref RpD3DTSIGN_GUNSIGNED
                            and \ref RpD3DTSIGN_BSIGNED, \ref RpD3DTSIGN_BUNSIGNED*/
    RwInt32 alphaKill; /**< specifies whether the alphakill is enabled or disabled for this stage. Valid values
                            are members of the \ref RpD3DTEXTUREALPHAKILL enumeration*/

    RwReal bumpEnvMat00; /**< specifies the floating point value for the [0][0] coefficient in a bump mapping
                              matrix.*/
    RwReal bumpEnvMat01; /**< specifies the floating point value for the [0][1] coefficient in a bump mapping
                              matrix.*/
    RwReal bumpEnvMat11; /**< specifies the floating point value for the [1][0] coefficient in a bump mapping
                              matrix.*/
    RwReal bumpEnvMat10; /**< specifies the floating point value for the [1][1] coefficient in a bump mapping
                              matrix.*/

    RwInt32 texCoordIndex; /**< specifies which set of texture coordinates should be used or how the
                                texture generation part of the GPU should generate texture coordinates. Valid values are
                                a \ref RwInt32 specifying the texture coordinate index in the geometry or one of these flags
                                \ref RpD3DTSS_TCI_PASSTHRU, \ref RpD3DTSS_TCI_CAMERASPACENORMAL, \ref RpD3DTSS_TCI_CAMERASPACEPOSITION
                                and \ref RpD3DTSS_TCI_CAMERASPACEREFLECTIONVECTOR,*/
    RwInt32 borderColor; /**< specifies which color should be used for rasterising pixels with texture coordinates
                              outside the [0.0,1.0] range. Valid value is a 32 bits RGBA value*/

    RpD3DMATRIX texTransformMatrix; /**< specifies the matrix used by the texture coordinates transformation used in this
                                         stage. Valid value is a \ref RpD3DMATRIX*/

};
typedef struct RpMatFXXboxStage RpMatFXXboxStage;

/**
 * \ingroup rpmatfxxboxex
 * \par RpMatFXXboxFinalBlend
 * The RpMatFXXboxFinalBlend supersedes the RenderWare blending modes. Blending should be enabled in
 * the material to use this structure.*/
struct RpMatFXXboxFinalBlend
{
    RwInt32 srcBlend; /**< specifies the source data for this blend. Valid values are members of the
                          \ref RpD3DBLEND enumeration */
    RwInt32 dstBlend; /**< specifies the destination data for this blend. Valid values are members of the
                         \ref RpD3DBLEND enumeration */
};
typedef struct RpMatFXXboxFinalBlend RpMatFXXboxFinalBlend;

/**
 * \ingroup rpmatfxxboxex
 * \par RpMatFXXboxMiscState
 * Other useful states in a multitexturing environment
 * \li textureFactor the color and alpha that can be used as another input in the stages.
 * valid value is a 32 bits RGBA color
 */
struct RpMatFXXboxMiscState
{
    RwInt32 textureFactor; /**< the color and alpha that can be used as another input in the stages.
                             valid value is a 32 bits RGBA color */
};
typedef struct RpMatFXXboxMiscState RpMatFXXboxMiscState;

/**
 * \ingroup rpmatfxxboxex
 * \par RpMatFXXboxMaterial
 * The main structure describing the RpMatFX material used for the multi-texture effect on the
 * Xbox
 * 
 */
struct RpMatFXXboxMaterial
{
    RwInt32 nbStages; /**< the number of active stages in this material. The maximum number of stages on
                            the Xbox is 4 */
    RpMatFXXboxStage *stages; /**< stages  an array of \ref RpMatFXXboxStage describing the pipeline setup for this material
                                  This array has nbStages entry */
    RpMatFXXboxFinalBlend blend; /**< a \ref RpMatFXXboxFinalBlend describing the blending to use on this material. This
                                     is only used if blending is enabled in the material */
    RpMatFXXboxMiscState miscState; /**< a \ref RpMatFXXboxMiscState describing the miscelleanous states to use on this material */
    void* userData; /**< a void pointer used to add additional data to the material */
};
typedef struct RpMatFXXboxMaterial RpMatFXXboxMaterial;

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

RpMTEffect *
RpXboxMTEffectCreate(RwUInt32   numStages);


extern RpMatFXXboxMaterial* RpXboxMTEffectGetConfig(const RpMTEffect *effect);

void
RpMatFXSetXboxMaterialUserData(const RpMTEffect *effect, void *userData);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* RPMATFX_MULTITEXXBOX_H */

/*---- end: c:/daily/rwsdk/plugin/matfx/xbox/multiTexXbox.h----*/

/******************************************************************************
 *  Enum types
 */

/**
 * \ingroup rpmatfxxbox
 * \ref RpMatFXXboxPipeline
 */
enum RpMatFXXboxPipeline
{
    rpNAMATFXXBOXPIPELINE          = 0,
    rpMATFXXBOXATOMICPIPELINE      = 1, /**<Xbox atomic material effect rendering pipeline. */
    rpMATFXXBOXWORLDSECTORPIPELINE = 2, /**<Xbox world sector material effect rendering pipeline. */
    rpMATFXXBOXPIPELINEMAX,
    rpMATFXXBOXPIPELINEFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RpMatFXXboxPipeline RpMatFXXboxPipeline;

/******************************************************************************
 *  Global types
 */

/******************************************************************************
 *  Functions
 */

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

extern RxPipeline *
RpMatFXGetXboxPipeline( RpMatFXXboxPipeline xboxPipeline );

#ifdef __cplusplus
}
#endif /* __cplusplus */

/*---- end: c:/daily/rwsdk/plugin/matfx/xbox/matfxplatform.h----*/

#endif /* RPMATFX_H */



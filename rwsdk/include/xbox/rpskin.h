
#ifndef RPSKIN_H
#define RPSKIN_H

/**
 * \defgroup rpskin RpSkin
 * \ingroup rpplugin
 *
 * Skin Plugin for RenderWare Graphics.
 */

/*===========================================================================*
 *--- Include files ---------------------------------------------------------*
 *===========================================================================*/
#include "rwcore.h"
#include "rpworld.h"

#include "rpcriter.h"
#include "rpskin.rpe"

#include "rphanim.h"

/*===========================================================================*
 *--- Global Types ----------------------------------------------------------*
 *===========================================================================*/
typedef struct RwMatrixWeights RwMatrixWeights;

/**
 * \ingroup rpskin
 * \struct RwMatrixWeights
 * A structure for defining up to four matrix weights per vertex.
 * Not all entries need to be used.
 *
 * \note
 * Values should be sorted, such that any zero 0.0f entries appear
 * after the valid weights. Any weights that appear after a zero
 * entry will be ignored.
 *
 * \see RpSkinCreate
 */
struct RwMatrixWeights
{
    RwReal w0; /**< The first matrix weight.  */
    RwReal w1; /**< The second matrix weight. */
    RwReal w2; /**< The third matrix weight.  */
    RwReal w3; /**< The fourth matrix weight. */
};

/**
 * \ingroup rpskin
 * \typedef RpSkin
 *
 * Skin object. This should be considered an opaque type.
 * Use the RpSkin API functions to access.
 *
 * \see RpSkinCreate
 * \see RpSkinDestroy
 */
typedef struct RpSkin RpSkin;

/*===========================================================================*
 *--- Plugin API Functions --------------------------------------------------*
 *===========================================================================*/
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

/*---------------------------------------------------------------------------*
 *-   Plugin functions                                                      -*
 *---------------------------------------------------------------------------*/
extern RwBool
RpSkinPluginAttach(void);

/*---------------------------------------------------------------------------*
 *-   Skin Atomic functions                                                 -*
 *---------------------------------------------------------------------------*/
extern RpAtomic *
RpSkinAtomicSetHAnimHierarchy( RpAtomic *atomic,
                               RpHAnimHierarchy *hierarchy );

extern RpHAnimHierarchy *
RpSkinAtomicGetHAnimHierarchy( const RpAtomic *atomic );

/*---------------------------------------------------------------------------*
 *-   Skin Geometry functions                                               -*
 *---------------------------------------------------------------------------*/
extern RpGeometry *
RpSkinGeometrySetSkin( RpGeometry *geometry,
                       RpSkin *skin );

extern RpSkin *
RpSkinGeometryGetSkin( RpGeometry *geometry );

extern RpSkin *
RpSkinCreate( RwUInt32 numVertices,
              RwUInt32 numBones,
              RwMatrixWeights *vertexWeights,
              RwUInt32 *vertexIndices,
              RwMatrix *inverseMatrices );

extern RpSkin *
RpSkinDestroy( RpSkin *skin );

extern RwUInt32
RpSkinGetNumBones( RpSkin *skin );

extern const RwMatrixWeights *
RpSkinGetVertexBoneWeights( RpSkin *skin );

extern const RwUInt32 *
RpSkinGetVertexBoneIndices( RpSkin *skin );

extern const RwMatrix *
RpSkinGetSkinToBoneMatrices( RpSkin *skin );

/*---------------------------------------------------------------------------*
 *-   Skin pipeline                                                         -*
 *---------------------------------------------------------------------------*/

/**
 * \ingroup rpskin
 * \ref RpSkinType defines the different ways a skinned atomic can
 * be rendered. Once a skinned \ref RpGeometry has been attached to
 * an \ref RpAtomic the atomic must be setup with the correct skin
 * rendering pipeline with \ref RpSkinAtomicSetType.
 */
enum RpSkinType
{
    rpNASKINTYPE        = 0, /**<Invalid skin pipeline.           */
    rpSKINTYPEGENERIC   = 1, /**<Generic skin rendering.          */
    rpSKINTYPEMATFX     = 2, /**<Material effects skin rendering. */
    rpSKINTYPETOON      = 3, /**<Toon skin rendering.             */
    rpSKINTYPEMATFXTOON = 4, /**<Note Toon + MatFX on same object NOT currently supported */
    rpSKINTYPEFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RpSkinType RpSkinType;

extern RpAtomic *
RpSkinAtomicSetType( RpAtomic *atomic,
                     RpSkinType type );

extern RpSkinType
RpSkinAtomicGetType( RpAtomic *atomic );

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif /* __cplusplus */

/*---------------------------------------------------------------------------*
 *-   Backwards macros                                                      -*
 *---------------------------------------------------------------------------*/

#define RpSkinAtomicGetSkin(_a)                                         \
    RpSkinGeometryGetSkin(RpAtomicGetGeometry(_a))

/*---------------------------------------------------------------------------*/

/*---- start: ./xbox/skinplatform.h----*/

/**
 * \defgroup rpskinxbox Xbox
 * \ingroup rpskin
 *
 * Xbox skin pipeline extension.
 */


/*===========================================================================*
 *--- Xbox Defines -----------------------------------------------------------*
 *===========================================================================*/

/*===========================================================================*
 *--- Xbox Global Types ------------------------------------------------------*
 *===========================================================================*/

/**
 * \ingroup rpskinxbox
 * \ref RpSkinXboxPipeline rendering pipelines available within the \ref RpSkin
 * plugin. Use \ref RpSkinGetXboxPipeline to retrieve the \ref RxPipeline s.
 */
enum RpSkinXboxPipeline
{
    rpNASKINXBOXPIPELINE              = 0,
    rpSKINXBOXPIPELINEGENERIC         = 1,
    /**<Xbox generic skin rendering pipeline.                           */
    rpSKINXBOXPIPELINEMATFX           = 2,
    /**<Xbox material effect skin rendering pipeline.                   */
    rpSKINXBOXPIPELINETOON            = 3,
    /**<Xbox toon skin rendering pipeline.                              */
    rpSKINXBOXPIPELINEMATFXTOON       = 4,
    /**<Xbox toon matfx skin rendering pipeline not supported           */
    rpSKINXBOXPIPELINEMAX,
    rpSKINXBOXPIPELINEFORCEENUMSIZEINT = RWFORCEENUMSIZEINT
};
typedef enum RpSkinXboxPipeline RpSkinXboxPipeline;

/*===========================================================================*
 *--- Xbox Plugin API Functions ----------------------------------------------*
 *===========================================================================*/
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
/*---------------------------------------------------------------------------*/

extern RxPipeline *
RpSkinGetXboxPipeline( RpSkinXboxPipeline xboxPipeline );

/*---------------------------------------------------------------------------*/
#ifdef __cplusplus
}
#endif /* __cplusplus */

/*---- end: ./xbox/skinplatform.h----*/

#endif /* RPSKIN_H */



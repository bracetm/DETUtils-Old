/*
 * 
 * DETUtils
 *
 * Since 2019., DEntisT
 *
 *
 *
 * - Library which provides in-game visible
 *   stuff.
 *
 *
 */

// Moved d_dmzone.inc here!
#include "d_visual_dmzones"

/*

                                                                                      
88b           d88              88                         db         88888888ba   88  
888b         d888              ""                        d88b        88      "8b  88  
88`8b       d8'88                                       d8'`8b       88      ,8P  88  
88 `8b     d8' 88  ,adPPYYba,  88  8b,dPPYba,          d8'  `8b      88aaaaaa8P'  88  
88  `8b   d8'  88  ""     `Y8  88  88P'   `"8a        d8YaaaaY8b     88""""""'    88  
88   `8b d8'   88  ,adPPPPP88  88  88       88       d8""""""""8b    88           88  
88    `888'    88  88,    ,88  88  88       88      d8'        `8b   88           88  
88     `8'     88  `"8bbdP"Y8  88  88       88     d8'          `8b  88           88  
                                                                                      
                                                                                      

*/

#include "d_visual_impl"
#include "d_visual_tdanims"

/*
                                                                      
88888888888                                                           
88                          ,d                                        
88                          88                                        
88aaaaa      8b,     ,d8  MM88MMM  8b,dPPYba,  ,adPPYYba,  ,adPPYba,  
88"""""       `Y8, ,8P'     88     88P'   "Y8  ""     `Y8  I8[    ""  
88              )888(       88     88          ,adPPPPP88   `"Y8ba,   
88            ,d8" "8b,     88,    88          88,    ,88  aa    ]8I  
88888888888  8P'     `Y8    "Y888  88          `"8bbdP"Y8  `"YbbdP"'  
                                                                      

*/

public OnDETUtilsInit()
{
    SetTimer("__Weapon_timer", 1000, true);
    LoadDETUtilsScript(DETUTILS_SCRIPT_VISUAL);
    #if defined DETUTILS_DEBUG_MODE
    SaveLogIntoFile("detutils_visual.log", "[DETUtils]: (debug) - Loading...");
    SaveLogIntoFile("detutils_visual.log", "[DETUtils]: (debug) - Loaded.");
    #endif
    if(funcidx("d_visual_detutilsinit") != -1)
    {
        CallLocalFunction("d_visual_detutilsinit", "");
    }
    return 1;
}

#if defined _ALS_OnDETUtilsInit
    #undef OnDETUtilsInit
#else
    #define _ALS_OnDETUtilsInit
#endif

#define OnDETUtilsInit( d_visual_detutilsinit(

forward d_visual_detutilsinit();

// cleanup

public OnDETUtilsExit()
{
    UnloadDETUtilsScript(DETUTILS_SCRIPT_VISUAL);
    if(funcidx("d_visual_detutilsexit") != -1)
    {
        CallLocalFunction("d_visual_detutilsexit", "");
    }
    return 1;
}

#if defined _ALS_OnDETUtilsExit
    #undef OnDETUtilsExit
#else
    #define _ALS_OnDETUtilsExit
#endif

#define OnDETUtilsExit( d_visual_detutilsexit(

forward d_visual_detutilsexit();
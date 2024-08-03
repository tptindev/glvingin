#ifndef LAYERIDS_H
#define LAYERIDS_H

class LayerIDs
{
public:
    enum MenuScene{
        MENU_LAYER_MIN,
        MENU_LAYER_0,
        MENU_LAYER_1,
        MENU_LAYER_2,
        MENU_LAYER_3,
        MENU_LAYER_4,
        MENU_LAYER_5,
        MENU_LAYER_6,
        MENU_LAYER_7,
        MENU_LAYER_8,
        MENU_LAYER_9,
        MENU_LAYER_MAX
    };

    enum GameScene{
        GAME_LAYER_MIN = MENU_LAYER_MAX,
        GAME_LAYER_0,
        GAME_LAYER_1,
        GAME_LAYER_2,
        GAME_LAYER_3,
        GAME_LAYER_4,
        GAME_LAYER_5,
        GAME_LAYER_6,
        GAME_LAYER_7,
        GAME_LAYER_8,
        GAME_LAYER_9,
        GAME_LAYER_MAX
    };
};

#endif // LAYERIDS_H

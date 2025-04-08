#ifndef TT_Block_HPP
#define TT_Block_HPP

namespace TankTek
{
    enum class BlockType
    {
        SOLID,
        TRANSPARENT,
        BILLBOARD,
        LIQUID
    };

    class Block
    {
        private:
            BlockType type;
    };
}

#endif

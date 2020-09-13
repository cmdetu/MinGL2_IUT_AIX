/**
 *
 * @file    sprite.cpp
 * @author  Alexandre Sollier
 * @date    Janvier 2020
 * @version 1.0
 * @brief   Image pouvant être chargé depuis un fichier
 *
 **/

#include "sprite.h"

#include <unistd.h>
#include <fcntl.h>
#include <iostream>

#include "../macros.h"
#include "../tools/myexception.h"

#define SPRITE nsGui::Sprite

SPRITE::Sprite(const std::string &filename, const Vec2D &position)
    : m_position(position)
{
    int fd = open(filename.c_str(), O_RDONLY);
    if (fd < 0)
    {
        std::cerr << "[DisplaySprite] Sprite file \"" << filename << "\" could not be opened." << std::endl;
        throw MyException(nsUtil::kFileNotFound);
    }

    FileBegin fileBegin;
    read(fd, &fileBegin, sizeof(FileBegin));

    for (uint32_t i = 0; i < fileBegin.pixelCount; ++i)
    {
        RGBAcolor color;
        read(fd, &color.Red,    sizeof(color.Red));
        read(fd, &color.Green,  sizeof(color.Green));
        read(fd, &color.Blue,   sizeof(color.Blue));
        read(fd, &color.Alpha,  sizeof(color.Alpha));

        m_pixelData.push_back(color);
    }

    close(fd);

    m_rowSize = fileBegin.rowSize;
}

nsGui::Sprite::Sprite(const std::vector<RGBAcolor> &pixelData, const uint32_t &rowSize, const Vec2D &position)
    : m_position(position)
    , m_rowSize(rowSize)
    , m_pixelData(pixelData)
{

}

std::unique_ptr<IDrawable> SPRITE::clone() const
{
    return std::unique_ptr<Sprite>(new Sprite(*this));
}

void SPRITE::draw()
{
    glBegin(GL_POINTS);

    for (unsigned i = 0; i < m_pixelData.size(); ++i)
    {
        const RGBAcolor actualColor = m_pixelData[i];
        const unsigned x = i % m_rowSize;
        const unsigned y = i / m_rowSize;

        glColor4ub(actualColor.Red, actualColor.Green, actualColor.Blue, actualColor.Alpha);
        glVertex2i(x + m_position.x, y + m_position.y);
    }

    glEnd();
}

const uint32_t& SPRITE::getRowSize() const
{
    return m_rowSize;
}

const std::vector<RGBAcolor>& SPRITE::getPixelData() const
{
    return m_pixelData;
}

const Vec2D& SPRITE::getPosition() const
{
    return m_position;
}

void SPRITE::setPosition(const Vec2D &position)
{
    m_position = position;
}

Vec2D SPRITE::computeSize() const
{
    return Vec2D(m_pixelData.size() / m_rowSize, m_rowSize);
}

#undef SPRITE

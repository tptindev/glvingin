#include "ALayer.h"

int ALayer::id() const
{
    return m_id;
}

void ALayer::setId(int newId)
{
    m_id = newId;
}

const char *ALayer::name() const
{
    return m_name;
}

void ALayer::setName(const char *newName)
{
    m_name = newName;
}

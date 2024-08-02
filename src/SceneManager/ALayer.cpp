#include "ALayer.h"
#include <Manager.h>

int ALayer::id() const
{
    return m_id;
}

void ALayer::setId(int newId)
{
    m_id = newId;
}

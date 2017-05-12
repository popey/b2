#include <shared/system.h>
#include "BeebState.h"
#include <shared/debug.h>
#include <beeb/DiscImage.h>
#include "misc.h"
#include <beeb/BBCMicro.h>

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

BeebState::BeebState(std::unique_ptr<BBCMicro> beeb):
    creation_time(GetUTCTimeNow()),
    m_beeb(std::move(beeb))
{
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

BeebState::~BeebState() {
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

uint64_t BeebState::GetEmulated2MHzCycles() const {
    return *m_beeb->GetNum2MHzCycles();
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

std::unique_ptr<BBCMicro> BeebState::CloneBBCMicro() const {
    return m_beeb->Clone();
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

const std::string &BeebState::GetName() const {
    return m_name;
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

void BeebState::SetName(std::string name) {
    m_name=name;
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

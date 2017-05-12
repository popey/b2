#ifndef HEADER_CEB00A5BE87C4598882E08BD09DE979B// -*- mode:c++ -*-
#define HEADER_CEB00A5BE87C4598882E08BD09DE979B

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// Some overlap between this and BeebThread...

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

class BeebState;
class DiscImage;
class BBCMicro;
struct SDL_PixelFormat;

#include <beeb/conf.h>
#include <memory>
#include "JobQueue.h"
#include "TVOutput.h"
#include "BeebConfig.h"

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

class GenerateThumbnailJob:
    public JobQueue::Job
{
public:
    ~GenerateThumbnailJob();

    bool Init(std::unique_ptr<BBCMicro> beeb,int num_frames,const SDL_PixelFormat *pixel_format);
    
    void ThreadExecute() override;

    const void *GetTextureData() const;
private:
    std::shared_ptr<BeebState> m_state;
    std::unique_ptr<DiscImage> m_disc_images[NUM_DRIVES];
    TVOutput m_tv_output;
    BBCMicro *m_beeb=nullptr;
    int m_num_frames=2;
    
    void Tick();
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#endif

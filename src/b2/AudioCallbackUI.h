#ifndef HEADER_8E9F48F66B734BF09EFD8580786ECA18// -*- mode:c++ -*-
#define HEADER_8E9F48F66B734BF09EFD8580786ECA18

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

class BeebWindow;

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

class AudioCallbackUI {
public:
    explicit AudioCallbackUI(BeebWindow *beeb_window);

    void DoImGui();
protected:
private:
    BeebWindow *m_beeb_window;
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#endif

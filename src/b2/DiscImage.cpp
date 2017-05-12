#include <shared/system.h>
#include <beeb/DiscImage.h>

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

static std::unique_ptr<DiscImage> DoClone(const DiscImage *disc_image) {
    if(!disc_image) {
        return nullptr;
    } else if(!disc_image->CanClone()) {
        return nullptr;
    } else {
        return disc_image->Clone();
    }
}

std::unique_ptr<DiscImage> DiscImage::Clone(const std::unique_ptr<DiscImage> &disc_image) {
    return DoClone(disc_image.get());
}

std::unique_ptr<DiscImage> DiscImage::Clone(const std::unique_ptr<const DiscImage> &disc_image) {
    return DoClone(disc_image.get());
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

DiscImage::DiscImage() {
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

DiscImage::~DiscImage() {
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

bool DiscImage::CanClone() const {
    return false;
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

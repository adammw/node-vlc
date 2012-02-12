//
//  VLCMedia.h
//  node-vlc
//
//  Created by Adam Malcontenti-Wilson on 16/12/11.
//  Copyright (c) 2012 Adam Malcontenti-Wilson. All rights reserved.
//

#ifndef VLCMedia_h
#define VLCMedia_h

#include <v8.h>
#include <node.h>

#include <vlc/vlc.h>

class VLCMedia : node::ObjectWrap
{
public:
    VLCMedia(const char* mrl);
    ~VLCMedia();
    
    static void Init(v8::Handle<v8::ObjectTemplate> target);
private:
    static v8::Handle<v8::Value> New(const v8::Arguments& args);
    
    
    libvlc_media_t * media_instance;
};
#endif

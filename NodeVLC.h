//
//  NodeVLC.h
//  node-vlc
//
//  Created by Adam Malcontenti-Wilson on 16/12/11.
//  Copyright (c) 2012 Adam Malcontenti-Wilson. All rights reserved.
//

#ifndef NodeVLC_h
#define NodeVLC_h

#include <v8.h>
#include <node.h>

#include <vlc/vlc.h>

class NodeVLC : node::ObjectWrap
{
public:
    NodeVLC();
    ~NodeVLC();
    
    static void Init(v8::Handle<v8::Object> target);
private:
    static v8::Handle<v8::Value> New(const v8::Arguments& args);
    static v8::Handle<v8::Value> GetChangeset(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> GetCompiler(v8::Local<v8::String> property, const v8::AccessorInfo& info);
    static v8::Handle<v8::Value> GetVersion(v8::Local<v8::String> property, const v8::AccessorInfo& info);

    libvlc_instance_t * vlc_instance;
};
#endif

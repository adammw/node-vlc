//
//  NodeVLC.cc
//  node-vlc
//
//  Created by Adam Malcontenti-Wilson on 16/12/11.
//  Copyright (c) 2012 Adam Malcontenti-Wilson. All rights reserved.
//


#include "NodeVLC.h"
#include "VLCMedia.h"

using namespace node;
using namespace v8;

NodeVLC::NodeVLC() : ObjectWrap() 
{
    vlc_instance = libvlc_new(0, NULL);
}

NodeVLC::~NodeVLC()
{
    libvlc_release(vlc_instance);
}

void NodeVLC::Init(Handle<Object> target)
{
    HandleScope scope; // used by v8 for garbage collection
    
    // Our constructor
    Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
    tpl->SetClassName(String::NewSymbol("VLC"));
    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->PrototypeTemplate()->SetAccessor(String::New("changeset"), GetChangeset);
    tpl->PrototypeTemplate()->SetAccessor(String::New("compiler"), GetCompiler);
    tpl->PrototypeTemplate()->SetAccessor(String::New("version"), GetVersion);
    
    // Instance methods
    VLCMedia::Init(tpl->PrototypeTemplate());
    
    // Static methods
    
    
    // Binding our constructor function to the target variable
    Persistent<Function> constructor = Persistent<Function>::New(tpl->GetFunction());
    target->Set(String::NewSymbol("VLC"), constructor);
}

Handle<Value> NodeVLC::New(const Arguments& args)
{
    HandleScope scope;
    
    if (!args.IsConstructCall())
        return ThrowException(Exception::TypeError(String::New("Constructor cannot be called as function, you need to use 'new' keyword")));
    
    NodeVLC* self = new NodeVLC();
    
    self->Wrap(args.This());
    
    return args.This();
}

Handle<Value> NodeVLC::GetChangeset(Local<String> property, const AccessorInfo& info)
{
    return String::New(libvlc_get_changeset());
}

Handle<Value> NodeVLC::GetCompiler(Local<String> property, const AccessorInfo& info)
{
    return String::New(libvlc_get_compiler());
}

Handle<Value> NodeVLC::GetVersion(Local<String> property, const AccessorInfo& info)
{
    return String::New(libvlc_get_version());
}

extern "C" {
    void init (Handle<Object> target)
    {
        NodeVLC::Init(target);
    }
    
    //NODE_MODULE(vlc, init)
}

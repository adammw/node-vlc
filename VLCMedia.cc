//
//  VLCMedia.h
//  node-vlc
//
//  Created by Adam Malcontenti-Wilson on 16/12/11.
//  Copyright (c) 2012 Adam Malcontenti-Wilson. All rights reserved.
//


#include "VLCMedia.h"

using namespace node;
using namespace v8;

VLCMedia::VLCMedia(const char* mrl) : ObjectWrap() 
{
    //media_instance = libvlc_media_new_location(libvlc_instance_t *p_instance, <#const char *psz_mrl#>)
}

VLCMedia::~VLCMedia()
{
   
}

void VLCMedia::Init(Handle<ObjectTemplate> target)
{
    HandleScope scope; // used by v8 for garbage collection
    
    // Our constructor
    Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
    tpl->SetClassName(String::NewSymbol("Media"));
    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    
    Persistent<Function> constructor = Persistent<Function>::New(tpl->GetFunction());
    // Instance methods
    
    
    // Static methods
    
    
    // Binding our constructor function to the target variable
    target->Set(String::NewSymbol("Media"), constructor);
}

Handle<Value> VLCMedia::New(const Arguments& args)
{
    HandleScope scope;
    
    if (!args.IsConstructCall())
        return ThrowException(Exception::TypeError(String::New("Constructor cannot be called as function, you need to use 'new' keyword")));
    
    if (args.Length() != 1 || !args[0]->IsString())
        return ThrowException(Exception::TypeError(String::New("Invalid arguments")));
    
    VLCMedia* self = new VLCMedia((char *)*args[0]);
    
    self->Wrap(args.This());
    
    return args.This();
}
/*
 * Copyright (C) 2011 Adobe Systems Incorporated. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer.
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials
 *    provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef WebKitNamedFlow_h
#define WebKitNamedFlow_h

#include <Node.h>
#include <wtf/ListHashSet.h>
#include <wtf/RefCounted.h>
#include <wtf/RefPtr.h>

namespace WebCore {

class NodeList;
class RenderNamedFlowThread;
class WebKitNamedFlowCollection;

class WebKitNamedFlow : public RefCounted<WebKitNamedFlow> {
public:
    static PassRefPtr<WebKitNamedFlow> create(PassRefPtr<WebKitNamedFlowCollection> manager, const AtomicString& flowThreadName);

    ~WebKitNamedFlow();

    const AtomicString& name() const;
    bool overset() const;
    int firstEmptyRegionIndex() const;
    PassRefPtr<NodeList> getRegionsByContent(Node*);
    PassRefPtr<NodeList> getContent();

    void setRenderer(RenderNamedFlowThread* parentFlowThread);

    enum FlowState {
        FlowStateCreated,
        FlowStateNull
    };

    FlowState flowState() const { return m_parentFlowThread ? FlowStateCreated : FlowStateNull; }

private:
    WebKitNamedFlow(PassRefPtr<WebKitNamedFlowCollection>, const AtomicString&);

    // The name of the flow thread as specified in CSS.
    AtomicString m_flowThreadName;

    RefPtr<WebKitNamedFlowCollection> m_flowManager;
    RenderNamedFlowThread* m_parentFlowThread;
};

}

#endif
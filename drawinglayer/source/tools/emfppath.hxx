/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */

#ifndef INCLUDED_DRAWINGLAYER_SOURCE_TOOLS_EMFPPATH_HXX
#define INCLUDED_DRAWINGLAYER_SOURCE_TOOLS_EMFPPATH_HXX

#include <emfphelperdata.hxx>
#include <memory>

namespace emfplushelper
{
    struct EMFPPath : public EMFPObject
    {
        ::basegfx::B2DPolyPolygon    aPolygon;
        sal_Int32                    nPoints;
        std::unique_ptr<float[]>     pPoints;
        std::unique_ptr<sal_uInt8[]> pPointTypes;

        EMFPPath(sal_Int32 _nPoints, bool bLines = false);

        virtual ~EMFPPath() override;

        // TODO: remove rR argument when debug code is no longer needed
        void Read(SvStream& s, sal_uInt32 pathFlags, EmfPlusHelperData const & rR);

        ::basegfx::B2DPolyPolygon& GetPolygon(EmfPlusHelperData& rR, bool bMapIt = true, bool bAddLineToCloseShape = false);
    };
}

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */

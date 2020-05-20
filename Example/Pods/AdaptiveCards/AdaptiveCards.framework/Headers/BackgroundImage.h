// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
#pragma once

#include "Enums.h"
#include "pch.h"
#include "BaseCardElement.h"

namespace AdaptiveSharedNamespace
{
    class BackgroundImage
    {
    public:
        BackgroundImage() :
            m_fillMode(ImageFillMode::Cover), m_hAlignment(HorizontalAlignment::Left), m_vAlignment(VerticalAlignment::Top)
        {
        }
        BackgroundImage(std::string const& url) : m_url(url) {}
        BackgroundImage(std::string const& url, ImageFillMode fillMode, HorizontalAlignment hAlignment, VerticalAlignment vAlignment) :
            m_url(url), m_fillMode(fillMode), m_hAlignment(hAlignment), m_vAlignment(vAlignment)
        {
        }

        std::string GetUrl() const;
        void SetUrl(const std::string& value);
        ImageFillMode GetFillMode() const;
        void SetFillMode(const ImageFillMode& value);
        HorizontalAlignment GetHorizontalAlignment() const;
        void SetHorizontalAlignment(const HorizontalAlignment& value);
        VerticalAlignment GetVerticalAlignment() const;
        void SetVerticalAlignment(const VerticalAlignment& value);

        Json::Value SerializeToJsonValue() const;

        static std::shared_ptr<BackgroundImage> Deserialize(const Json::Value& json);

    private:
        std::string m_url;
        ImageFillMode m_fillMode = ImageFillMode::Cover;
        HorizontalAlignment m_hAlignment = HorizontalAlignment::Left;
        VerticalAlignment m_vAlignment = VerticalAlignment::Top;
    };
}

// clang-format off

// This file is generated. Edit scripts/generate-style-code.js, then run `make style-code`.

#include <mbgl/style/layers/heatmap_layer.hpp>
#include <mbgl/style/layers/heatmap_layer_impl.hpp>
#include <mbgl/style/layer_observer.hpp>
#include <mbgl/style/conversion/color_ramp_property_value.hpp>
#include <mbgl/style/conversion/constant.hpp>
#include <mbgl/style/conversion/property_value.hpp>
#include <mbgl/style/conversion/transition_options.hpp>
#include <mbgl/style/conversion/json.hpp>
#include <mbgl/style/conversion_impl.hpp>
#include <mbgl/util/traits.hpp>

#include <mapbox/eternal.hpp>

namespace mbgl {
namespace style {


// static
const LayerTypeInfo* HeatmapLayer::Impl::staticTypeInfo() noexcept {
    const static LayerTypeInfo typeInfo{.type="heatmap",
                                        .source=LayerTypeInfo::Source::Required,
                                        .pass3d=LayerTypeInfo::Pass3D::Required,
                                        .layout=LayerTypeInfo::Layout::NotRequired,
                                        .fadingTiles=LayerTypeInfo::FadingTiles::NotRequired,
                                        .crossTileIndex=LayerTypeInfo::CrossTileIndex::NotRequired,
                                        .tileKind=LayerTypeInfo::TileKind::Geometry};
    return &typeInfo;
}

HeatmapLayer::HeatmapLayer(const std::string& layerID, const std::string& sourceID)
    : Layer(makeMutable<Impl>(layerID, sourceID)) {
}

HeatmapLayer::HeatmapLayer(Immutable<Impl> impl_)
    : Layer(std::move(impl_)) {
}

HeatmapLayer::~HeatmapLayer() = default;

const HeatmapLayer::Impl& HeatmapLayer::impl() const {
    return static_cast<const Impl&>(*baseImpl);
}

Mutable<HeatmapLayer::Impl> HeatmapLayer::mutableImpl() const {
    return makeMutable<Impl>(impl());
}

std::unique_ptr<Layer> HeatmapLayer::cloneRef(const std::string& id_) const {
    auto impl_ = mutableImpl();
    impl_->id = id_;
    impl_->paint = HeatmapPaintProperties::Transitionable();
    return std::make_unique<HeatmapLayer>(std::move(impl_));
}

void HeatmapLayer::Impl::stringifyLayout(rapidjson::Writer<rapidjson::StringBuffer>&) const {
}

// Layout properties


// Paint properties

ColorRampPropertyValue HeatmapLayer::getDefaultHeatmapColor() {
    conversion::Error error;
    std::string rawValue = R"JSON(["interpolate",["linear"],["heatmap-density"],0,"rgba(0, 0, 255, 0)",0.1,"royalblue",0.3,"cyan",0.5,"lime",0.7,"yellow",1,"red"])JSON";
    return *conversion::convertJSON<ColorRampPropertyValue>(rawValue, error);
}

const ColorRampPropertyValue& HeatmapLayer::getHeatmapColor() const {
    return impl().paint.template get<HeatmapColor>().value;
}

void HeatmapLayer::setHeatmapColor(const ColorRampPropertyValue& value) {
    if (value == getHeatmapColor())
        return;
    auto impl_ = mutableImpl();
    impl_->paint.template get<HeatmapColor>().value = value;
    baseImpl = std::move(impl_);
    observer->onLayerChanged(*this);
}

void HeatmapLayer::setHeatmapColorTransition(const TransitionOptions& options) {
    auto impl_ = mutableImpl();
    impl_->paint.template get<HeatmapColor>().options = options;
    baseImpl = std::move(impl_);
}

TransitionOptions HeatmapLayer::getHeatmapColorTransition() const {
    return impl().paint.template get<HeatmapColor>().options;
}

PropertyValue<float> HeatmapLayer::getDefaultHeatmapIntensity() {
    return {1.f};
}

const PropertyValue<float>& HeatmapLayer::getHeatmapIntensity() const {
    return impl().paint.template get<HeatmapIntensity>().value;
}

void HeatmapLayer::setHeatmapIntensity(const PropertyValue<float>& value) {
    if (value == getHeatmapIntensity())
        return;
    auto impl_ = mutableImpl();
    impl_->paint.template get<HeatmapIntensity>().value = value;
    baseImpl = std::move(impl_);
    observer->onLayerChanged(*this);
}

void HeatmapLayer::setHeatmapIntensityTransition(const TransitionOptions& options) {
    auto impl_ = mutableImpl();
    impl_->paint.template get<HeatmapIntensity>().options = options;
    baseImpl = std::move(impl_);
}

TransitionOptions HeatmapLayer::getHeatmapIntensityTransition() const {
    return impl().paint.template get<HeatmapIntensity>().options;
}

PropertyValue<float> HeatmapLayer::getDefaultHeatmapOpacity() {
    return {1.f};
}

const PropertyValue<float>& HeatmapLayer::getHeatmapOpacity() const {
    return impl().paint.template get<HeatmapOpacity>().value;
}

void HeatmapLayer::setHeatmapOpacity(const PropertyValue<float>& value) {
    if (value == getHeatmapOpacity())
        return;
    auto impl_ = mutableImpl();
    impl_->paint.template get<HeatmapOpacity>().value = value;
    baseImpl = std::move(impl_);
    observer->onLayerChanged(*this);
}

void HeatmapLayer::setHeatmapOpacityTransition(const TransitionOptions& options) {
    auto impl_ = mutableImpl();
    impl_->paint.template get<HeatmapOpacity>().options = options;
    baseImpl = std::move(impl_);
}

TransitionOptions HeatmapLayer::getHeatmapOpacityTransition() const {
    return impl().paint.template get<HeatmapOpacity>().options;
}

PropertyValue<float> HeatmapLayer::getDefaultHeatmapRadius() {
    return {30.f};
}

const PropertyValue<float>& HeatmapLayer::getHeatmapRadius() const {
    return impl().paint.template get<HeatmapRadius>().value;
}

void HeatmapLayer::setHeatmapRadius(const PropertyValue<float>& value) {
    if (value == getHeatmapRadius())
        return;
    auto impl_ = mutableImpl();
    impl_->paint.template get<HeatmapRadius>().value = value;
    baseImpl = std::move(impl_);
    observer->onLayerChanged(*this);
}

void HeatmapLayer::setHeatmapRadiusTransition(const TransitionOptions& options) {
    auto impl_ = mutableImpl();
    impl_->paint.template get<HeatmapRadius>().options = options;
    baseImpl = std::move(impl_);
}

TransitionOptions HeatmapLayer::getHeatmapRadiusTransition() const {
    return impl().paint.template get<HeatmapRadius>().options;
}

PropertyValue<float> HeatmapLayer::getDefaultHeatmapWeight() {
    return {1.f};
}

const PropertyValue<float>& HeatmapLayer::getHeatmapWeight() const {
    return impl().paint.template get<HeatmapWeight>().value;
}

void HeatmapLayer::setHeatmapWeight(const PropertyValue<float>& value) {
    if (value == getHeatmapWeight())
        return;
    auto impl_ = mutableImpl();
    impl_->paint.template get<HeatmapWeight>().value = value;
    baseImpl = std::move(impl_);
    observer->onLayerChanged(*this);
}

void HeatmapLayer::setHeatmapWeightTransition(const TransitionOptions& options) {
    auto impl_ = mutableImpl();
    impl_->paint.template get<HeatmapWeight>().options = options;
    baseImpl = std::move(impl_);
}

TransitionOptions HeatmapLayer::getHeatmapWeightTransition() const {
    return impl().paint.template get<HeatmapWeight>().options;
}

using namespace conversion;

namespace {

constexpr uint8_t kPaintPropertyCount = 10u;

enum class Property : uint8_t {
    HeatmapColor,
    HeatmapIntensity,
    HeatmapOpacity,
    HeatmapRadius,
    HeatmapWeight,
    HeatmapColorTransition,
    HeatmapIntensityTransition,
    HeatmapOpacityTransition,
    HeatmapRadiusTransition,
    HeatmapWeightTransition,
};

template <typename T>
constexpr uint8_t toUint8(T t) noexcept {
    return uint8_t(mbgl::underlying_type(t));
}

constexpr const auto layerProperties = mapbox::eternal::hash_map<mapbox::eternal::string, uint8_t>(
    {{"heatmap-color", toUint8(Property::HeatmapColor)},
     {"heatmap-intensity", toUint8(Property::HeatmapIntensity)},
     {"heatmap-opacity", toUint8(Property::HeatmapOpacity)},
     {"heatmap-radius", toUint8(Property::HeatmapRadius)},
     {"heatmap-weight", toUint8(Property::HeatmapWeight)},
     {"heatmap-color-transition", toUint8(Property::HeatmapColorTransition)},
     {"heatmap-intensity-transition", toUint8(Property::HeatmapIntensityTransition)},
     {"heatmap-opacity-transition", toUint8(Property::HeatmapOpacityTransition)},
     {"heatmap-radius-transition", toUint8(Property::HeatmapRadiusTransition)},
     {"heatmap-weight-transition", toUint8(Property::HeatmapWeightTransition)}});

StyleProperty getLayerProperty(const HeatmapLayer& layer, Property property) {
    switch (property) {
        case Property::HeatmapColor:
            return makeStyleProperty(layer.getHeatmapColor());
        case Property::HeatmapIntensity:
            return makeStyleProperty(layer.getHeatmapIntensity());
        case Property::HeatmapOpacity:
            return makeStyleProperty(layer.getHeatmapOpacity());
        case Property::HeatmapRadius:
            return makeStyleProperty(layer.getHeatmapRadius());
        case Property::HeatmapWeight:
            return makeStyleProperty(layer.getHeatmapWeight());
        case Property::HeatmapColorTransition:
            return makeStyleProperty(layer.getHeatmapColorTransition());
        case Property::HeatmapIntensityTransition:
            return makeStyleProperty(layer.getHeatmapIntensityTransition());
        case Property::HeatmapOpacityTransition:
            return makeStyleProperty(layer.getHeatmapOpacityTransition());
        case Property::HeatmapRadiusTransition:
            return makeStyleProperty(layer.getHeatmapRadiusTransition());
        case Property::HeatmapWeightTransition:
            return makeStyleProperty(layer.getHeatmapWeightTransition());
    }
    return {};
}

StyleProperty getLayerProperty(const HeatmapLayer& layer, const std::string& name) {
    const auto it = layerProperties.find(name.c_str());
    if (it == layerProperties.end()) {
        return {};
    }
    return getLayerProperty(layer, static_cast<Property>(it->second));
}

} // namespace

Value HeatmapLayer::serialize() const {
    auto result = Layer::serialize();
    assert(result.getObject());
    for (const auto& property : layerProperties) {
        auto styleProperty = getLayerProperty(*this, static_cast<Property>(property.second));
        if (styleProperty.getKind() == StyleProperty::Kind::Undefined) continue;
        serializeProperty(result, styleProperty, property.first.c_str(), property.second < kPaintPropertyCount);
    }
    return result;
}

std::optional<Error> HeatmapLayer::setPropertyInternal(const std::string& name, const Convertible& value) {
    const auto it = layerProperties.find(name.c_str());
    if (it == layerProperties.end()) return Error{"layer doesn't support this property"};

    auto property = static_cast<Property>(it->second);

    if (property == Property::HeatmapColor) {
        Error error;
        const auto& typedValue = convert<ColorRampPropertyValue>(value, error, false, false);
        if (!typedValue) {
            return error;
        }

        setHeatmapColor(*typedValue);
        return std::nullopt;
    }
    if (property == Property::HeatmapIntensity || property == Property::HeatmapOpacity) {
        Error error;
        const auto& typedValue = convert<PropertyValue<float>>(value, error, false, false);
        if (!typedValue) {
            return error;
        }

        if (property == Property::HeatmapIntensity) {
            setHeatmapIntensity(*typedValue);
            return std::nullopt;
        }

        if (property == Property::HeatmapOpacity) {
            setHeatmapOpacity(*typedValue);
            return std::nullopt;
        }
    }
    if (property == Property::HeatmapRadius || property == Property::HeatmapWeight) {
        Error error;
        const auto& typedValue = convert<PropertyValue<float>>(value, error, true, false);
        if (!typedValue) {
            return error;
        }

        if (property == Property::HeatmapRadius) {
            setHeatmapRadius(*typedValue);
            return std::nullopt;
        }

        if (property == Property::HeatmapWeight) {
            setHeatmapWeight(*typedValue);
            return std::nullopt;
        }
    }

    Error error;
    std::optional<TransitionOptions> transition = convert<TransitionOptions>(value, error);
    if (!transition) {
        return error;
    }

    if (property == Property::HeatmapColorTransition) {
        setHeatmapColorTransition(*transition);
        return std::nullopt;
    }

    if (property == Property::HeatmapIntensityTransition) {
        setHeatmapIntensityTransition(*transition);
        return std::nullopt;
    }

    if (property == Property::HeatmapOpacityTransition) {
        setHeatmapOpacityTransition(*transition);
        return std::nullopt;
    }

    if (property == Property::HeatmapRadiusTransition) {
        setHeatmapRadiusTransition(*transition);
        return std::nullopt;
    }

    if (property == Property::HeatmapWeightTransition) {
        setHeatmapWeightTransition(*transition);
        return std::nullopt;
    }

    return Error{"layer doesn't support this property"};
}

StyleProperty HeatmapLayer::getProperty(const std::string& name) const {
    return getLayerProperty(*this, name);
}

Mutable<Layer::Impl> HeatmapLayer::mutableBaseImpl() const {
    return staticMutableCast<Layer::Impl>(mutableImpl());
}

} // namespace style
} // namespace mbgl

// clang-format on

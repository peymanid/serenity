#include "VBWidgetPropertyModel.h"
#include "VBWidget.h"
#include "VBProperty.h"

VBWidgetPropertyModel::VBWidgetPropertyModel(VBWidget& widget)
    : m_widget(widget)
{
}

VBWidgetPropertyModel::~VBWidgetPropertyModel()
{
    ASSERT_NOT_REACHED();
}

int VBWidgetPropertyModel::row_count(const GModelIndex&) const
{
    return m_widget.m_properties.size();
}

String VBWidgetPropertyModel::column_name(int column) const
{
    switch (column) {
    case Column::Name: return "Name";
    case Column::Value: return "Value";
    default: ASSERT_NOT_REACHED();
    }
}

GModel::ColumnMetadata VBWidgetPropertyModel::column_metadata(int column) const
{
    UNUSED_PARAM(column);
    return { 100, TextAlignment::CenterLeft };
}

GVariant VBWidgetPropertyModel::data(const GModelIndex& index, Role role) const
{
    if (role == Role::Display) {
        auto& property = *m_widget.m_properties[index.row()];
        auto value = property.value();
        switch (index.column()) {
        case Column::Name: return property.name();
        case Column::Value: return property.value();
        }
    }
    return { };
}
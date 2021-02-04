/****************************************************************************/
// Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
// Copyright (C) 2001-2021 German Aerospace Center (DLR) and others.
// This program and the accompanying materials are made available under the
// terms of the Eclipse Public License 2.0 which is available at
// https://www.eclipse.org/legal/epl-2.0/
// This Source Code may also be made available under the following Secondary
// Licenses when the conditions for such availability set forth in the Eclipse
// Public License 2.0 are satisfied: GNU General Public License, version 2
// or later which is available at
// https://www.gnu.org/licenses/old-licenses/gpl-2.0-standalone.html
// SPDX-License-Identifier: EPL-2.0 OR GPL-2.0-or-later
/****************************************************************************/
/// @file    GNEMatchGenericDataAttribute.h
/// @author  Pablo Alvarez Lopez
/// @date    Feb 2020
///
// The Widget for modifying selections of network-elements
// (some elements adapted from GUIDialog_GLChosenEditor)
/****************************************************************************/
#pragma once
#include <config.h>

#include "GNESelectorFrame.h"

// ===========================================================================
// class definitions
// ===========================================================================

class GNEMatchAttribute : protected FXGroupBox {
    /// @brief FOX-declaration
    FXDECLARE(GNEMatchAttribute)

public:
    /// @brief constructor
    GNEMatchAttribute(GNESelectorFrame* selectorFrameParent);

    /// @brief destructor
    ~GNEMatchAttribute();

    /// @brief enable match attributes
    void enableMatchAttribute();

    /// @brief disable match attributes
    void disableMatchAttribute();

    /// @brief show match attributes
    void showMatchAttribute();

    /// @brief hide match attributes
    void hideMatchAttribute();

    /// @name FOX-callbacks
    /// @{

    /**@brief Called when the user selectes a tag in the match box
     * @note updates the attr listbox and repaints itself
     */
    long onCmdSelMBTag(FXObject*, FXSelector, void*);

    /**@brief Called when the user selectes a tag in the match box
     * @note updates the attr listbox and repaints itself
     */
    long onCmdSelMBAttribute(FXObject*, FXSelector, void*);

    /**@brief Called when the user enters a new selection expression
     * @note validates expression and modifies current selection
     */
    long onCmdSelMBString(FXObject*, FXSelector, void*);

    /**@brief Called when the user clicks the help button
     * @note pop up help window
     */
    long onCmdHelp(FXObject*, FXSelector, void*);

    /// @}

protected:
    /// @brief FOX need this
    FOX_CONSTRUCTOR(GNEMatchAttribute)

private:
    /// @brief pointer to Selector Frame Parent
    GNESelectorFrame* mySelectorFrameParent;

    /// @brief tag of the match box
    FXComboBox* myMatchTagComboBox;

    /// @brief attributes of the match box
    FXComboBox* myMatchAttrComboBox;

    /// @brief current SumoXMLTag tag
    SumoXMLTag myCurrentTag;

    /// @brief current SumoXMLTag Attribute
    SumoXMLAttr myCurrentAttribute;

    /// @brief string of the match
    FXTextField* myMatchString;

    /// @brief match string button
    FXButton* myMatchStringButton;

    /// @brief Invalidated copy constructor.
    GNEMatchAttribute(const GNEMatchAttribute&) = delete;

    /// @brief Invalidated assignment operator.
    GNEMatchAttribute& operator=(const GNEMatchAttribute&) = delete;
};

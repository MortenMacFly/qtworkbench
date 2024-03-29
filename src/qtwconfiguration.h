/***************************************************************
 * Name:      QtWConfiguration.h
 * Purpose:   Code::Blocks plugin
 * Author:    Yorgos Pagles<y.pagles@gmail.com>
 * Copyright: (c) Yorgos Pagles
 * License:   GPL
 **************************************************************/

#ifndef QTWCONFIGURATION_H
#define QTWCONFIGURATION_H

#include "configurationpanel.h"

class QtWConfiguration : public cbConfigurationPanel
{
public:
    QtWConfiguration(wxWindow* parent);
    virtual ~QtWConfiguration();

protected:
    virtual wxString GetTitle() const
    {
        return _("Qt Workbench");
    }
    virtual wxString GetBitmapBaseName() const
    {
        return _T("generic-plugin");
    }
    virtual void OnApply()
    {
        SaveSettings();
    }
    virtual void OnCancel()
    {}

    void OnBrowseQtMakeSpec(wxCommandEvent& event);
    void OnBrowseQtDir(wxCommandEvent& event);
    void OnReReadQMakeSpecs(wxCommandEvent& event);

    void LoadSettings();
    void SaveSettings();

    void PopulateMkSpecs(const wxString &QMakeSpecDir);
private:
    DECLARE_EVENT_TABLE()
};

#endif

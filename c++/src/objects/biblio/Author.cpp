/* $Id: Author.cpp 272611 2011-04-08 18:57:08Z ucko $
 * ===========================================================================
 *
 *                            PUBLIC DOMAIN NOTICE
 *               National Center for Biotechnology Information
 *
 *  This software/database is a "United States Government Work" under the
 *  terms of the United States Copyright Act.  It was written as part of
 *  the author's official duties as a United States Government employee and
 *  thus cannot be copyrighted.  This software/database is freely available
 *  to the public for use. The National Library of Medicine and the U.S.
 *  Government have not placed any restriction on its use or reproduction.
 *
 *  Although all reasonable efforts have been taken to ensure the accuracy
 *  and reliability of the software and data, the NLM and the U.S.
 *  Government do not and cannot warrant the performance or results that
 *  may be obtained by using this software or data. The NLM and the U.S.
 *  Government disclaim all warranties, express or implied, including
 *  warranties of performance, merchantability or fitness for any particular
 *  purpose.
 *
 *  Please cite the author in any work or product based on this material.
 *
 * ===========================================================================
 *
 * Author:  .......
 *
 * File Description:
 *   .......
 *
 * Remark:
 *   This code was originally generated by application DATATOOL
 *   using the following specifications:
 *   'biblio.asn'.
 */

// standard includes
#include <ncbi_pch.hpp>
#include <objects/general/Person_id.hpp>

// generated includes
#include <objects/biblio/Author.hpp>

// generated classes

BEGIN_NCBI_SCOPE

BEGIN_objects_SCOPE // namespace ncbi::objects::

// destructor
CAuthor::~CAuthor(void)
{
}


bool CAuthor::GetLabelV1(string* label, TLabelFlags) const
{
    // XXX - honor flags?
    GetName().GetLabel(label);
    return true;
}


bool CAuthor::GetLabelV2(string* label, TLabelFlags flags) const
{
    const CPerson_id& pid = GetName();
    switch (pid.Which()) {
    case CPerson_id::e_Name:
    {
        const CName_std& name = pid.GetName();
        if (HasText(name.GetLast())) {
            return x_GetLabelV2
                (label, flags, name.GetLast(),
                 name.CanGetInitials() ? name.GetInitials() : kEmptyStr,
                 name.CanGetSuffix() ? name.GetSuffix() : kEmptyStr);
        } else if (name.IsSetFull()  &&  HasText(name.GetFull())) {
            return x_GetLabelV2(label, flags, name.GetFull());
        } else {
            return false;
        }
    }
    case CPerson_id::e_Ml:
        return x_GetLabelV2(label, flags, pid.GetMl());
    case CPerson_id::e_Str:
        return x_GetLabelV2(label, flags, pid.GetStr()); 
    case CPerson_id::e_Consortium:
        return x_GetLabelV2(label, flags, pid.GetConsortium());
    default:
        return false;
    }
}


bool CAuthor::x_GetLabelV2(string* label, TLabelFlags flags, CTempString name,
                           CTempString initials, CTempString suffix)
{
    if (name.empty()) {
        return false;
    }

    if (name.size() <= 6  &&  (SWNC(name, "et al")  ||  SWNC(name, "et,al"))) {
        name = "et al.";
        if (NStr::EndsWith(*label, " and ")) {
            label->replace(label->size() - 5, NPOS, ", ");
        }
    }

    SIZE_TYPE pos = label->size();
    *label += name;
    if (HasText(initials)) {
        *label += ',';
        *label += initials;
    }
    if (HasText(suffix)) {
        *label += ' ';
        *label += suffix;
    }

    if ((flags & fLabel_FlatEMBL) != 0) {
        NStr::ReplaceInPlace(*label, ",", " ", pos);
    }

    return true;
}

END_objects_SCOPE // namespace ncbi::objects::

END_NCBI_SCOPE

/* Original file checksum: lines: 65, chars: 1880, CRC32: f9047a4f */

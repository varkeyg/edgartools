#include "insider.h"

#include <iostream>

#include "common.h"

using namespace std;

void Insider::getTransactions() {
    auto filing = httpGet(url);
    string end_flag = "</ownershipDocument>";
    auto start = filing.find("<ownershipDocument>");
    auto end = filing.find(end_flag) - start + end_flag.length();

    filing = filing.substr(start, end);
    tinyxml2::XMLDocument doc;
    doc.Parse(filing.c_str());
    if (!doc.Error()) {
        auto owner_doc = doc.FirstChildElement("ownershipDocument");
        setHeader(owner_doc);
        getNonDerivativeTransactions(owner_doc);
        printTransactions();
    }
}

///////////////////////////////////////////////////////////////////////////////

void Insider::setHeader(xmldoc* doc) {
    //Issuer
    auto issuer = doc->FirstChildElement("issuer");
    fheader.issuerCik = issuer->FirstChildElement("issuerCik")->GetText();
    fheader.issuerName = issuer->FirstChildElement("issuerName")->GetText();
    fheader.issuerSym = issuer->FirstChildElement("issuerTradingSymbol")->GetText();

    //Reporting Owner
    auto owner = doc->FirstChildElement("reportingOwner")->FirstChildElement("reportingOwnerId");
    fheader.rptOwnerCik = owner->FirstChildElement("rptOwnerCik")->GetText();
    fheader.rptOwnerName = owner->FirstChildElement("rptOwnerName")->GetText();

    //Owner and Issuer Relationship can be Director or officer.
    //Director
    string relation{"Unk"};
    auto rel = doc->FirstChildElement("reportingOwner")->FirstChildElement("reportingOwnerRelationship");
    auto director = rel->FirstChildElement("isDirector");
    if (director != nullptr) {
        if ((string)director->GetText() == "1") {
            relation = "Director";
        }
    }

    //Corporate offier
    auto officer = rel->FirstChildElement("isOfficer");
    if (officer != nullptr) {
        if ((string)officer->GetText() == "1") {
            relation = rel->FirstChildElement("officerTitle")->GetText();
        }
    }
    fheader.rptOwnerRelation = relation;
};

///////////////////////////////////////////////////////////////////////////////

void Insider::getNonDerivativeTransactions(xmldoc* doc) {
    auto ndtable = doc->FirstChildElement("nonDerivativeTable");
    if (ndtable != nullptr) {
        auto ndtxn = ndtable->FirstChildElement("nonDerivativeTransaction");
        while (ndtxn != nullptr) {
            ins_txns.issuerCik.push_back(fheader.issuerCik);
            ins_txns.issuerName.push_back(fheader.issuerName);
            ins_txns.issuerSym.push_back(fheader.issuerSym);
            ins_txns.rptOwnerCik.push_back(fheader.rptOwnerCik);
            ins_txns.rptOwnerName.push_back(fheader.rptOwnerName);
            ins_txns.rptOwnerRelation.push_back(fheader.rptOwnerRelation);
            ndtxn = ndtxn->NextSiblingElement();
        }
    }
};

///////////////////////////////////////////////////////////////////////////////

void Insider::printTransactions() {
    cout << "\n"
         << endl;
    cout << packString("issuerCik", 15)
         << packString("issuerName", 20)
         << packString("issuerSym", 20)
         //<< packString(ins_txns.rptOwnerCik[i], 20)
         << packString("OwnerName", 20)
         << packString("Relation", 20)
         << endl;

    cout << "================================================================================================================" << endl;
    for (int i = 0; i < ins_txns.issuerCik.size(); i++) {
        cout << packString(ins_txns.issuerCik[i], 15)
             << packString(ins_txns.issuerName[i], 20)
             << packString(ins_txns.issuerSym[i], 20)
             // << packString(ins_txns.rptOwnerCik[i], 20)
             << packString(ins_txns.rptOwnerName[i], 20)
             << packString(ins_txns.rptOwnerRelation[i], 20)
             << endl;
    }
    cout << "\n"
         << endl;
};
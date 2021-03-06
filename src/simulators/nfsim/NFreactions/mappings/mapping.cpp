


#include "mapping.hh"

using namespace NF;


NF::Mapping::Mapping(unsigned int type, int index)
{
	this->type = type;
	this->index = index;
	this->m=NULL;
}
NF::Mapping::~Mapping()
{
	index=0;
	clear();
}


unsigned int NF::Mapping::getType() const
{
	return this->type;
}
int NF::Mapping::getIndex() const
{
	return this->index;
}


void NF::Mapping::clear()
{
	//Clearing the Mapping only requires us to set the molecule to null
	this->m=NULL;
}
bool NF::Mapping::setMolecule(Molecule *m)
{
	this->m = m;
	return true;
}


void NF::Mapping::printDetails() const { printDetails(cout); }
void NF::Mapping::printDetails(ostream &o) const
{
	o<<"M("<<index<<","<<type<<"): mapped to: ";
	//cout<<"here"<<endl;
	if(m!=NULL) {
		o<<m->getMoleculeTypeName()<<"_"<<m->getUniqueID();
		m->printDetails();
	}
	else o<<"nothing.";

}


void NF::Mapping::clone(Mapping *original, Mapping *newClone)
{
	//Before we clone, we have to make sure the newClone Mapping
	//is the right type and can accept the clone
	if(original->index!=newClone->index || original->type!=newClone->type) {
		cerr<<"Error in Mapping!! : When cloning an existing Mapping into a new Mapping,\n";
		cerr<<"the new Mapping has a different index and/or type!  That means you cannot\n";
		cerr<<"clone the original onto this Mapping!"<<endl;
		exit(1);
	}

	//Assign properly the molecule
	newClone->m=original->m;
}



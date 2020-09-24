#include "notesmodel.h"

NotesModel::NotesModel(QObject *parent) : QObject(parent)
{

}

void NotesModel::addNote(const NoteItem& note) {
    //if already present then not add new but instead change
    for(int i = 0; i < notes.count(); i++) {
        if(notes.at(i).id == note.id){
            notes[i] = note;
            return;
        }
    }

    //if not already present then append a new
    notes.append(note);
}

void NotesModel::removeNote(int id){
    for(int i = 0; i < notes.count(); i++) {
        if(notes.at(i).id == id) {
            notes.remove(i);
            break;
        }
    }
}

NoteItem NotesModel::newNoteItem(int id, int x, int y, const QString& text)
{
    return NoteItem(id, x, y, text);
}

int NotesModel::getFreeUniqueId() const
{
    int randValue;
    do {
        randValue = rand();
    } while (isAnIdAlreadyUsed(randValue));
    return randValue;
}

bool NotesModel::isAnIdAlreadyUsed(int id) const
{
    for(int i = 0; i < notes.count(); i++) {
        if(notes.at(i).id == id)
            return true;
    }
    return false;
}

NoteItem NotesModel::getUsingInternalArrayId(int id) const
{
    return notes.at(id);
}

NoteItem NotesModel::getUsingUniqueId(int uniqueId) const {
    for(int i = 0; i < notes.count(); i++) {
        if(notes.at(i).id == uniqueId)
            return notes.at(i);
    }
    Q_ASSERT(false);
    return NoteItem();
}

int NotesModel::count() const {
    return notes.count();
}


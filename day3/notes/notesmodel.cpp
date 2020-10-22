#include "notesmodel.h"

NotesModel::NotesModel(QObject *parent) : QObject(parent)
{

}

void NotesModel::addNote(const NoteItem& note) {
    //if already present then not add new but instead change
    for(int i = 0; i < m_notes.count(); i++) {
        if(m_notes[i].m_id == note.m_id){
            m_notes[i] = note;
            return;
        }
    }

    //if not already present then append a new
    m_notes.append(note);
    emit countChanged(m_notes.count());
}

void NotesModel::removeNote(int id){
    for(int i = 0; i < m_notes.count(); i++) {
        if(m_notes[i].m_id == id) {
            m_notes.remove(i);
            emit countChanged(m_notes.count());
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
    for(int i = 0; i < m_notes.count(); i++) {
        if(m_notes[i].m_id == id)
            return true;
    }
    return false;
}

NoteItem NotesModel::getUsingInternalArrayId(int id) const
{
    return m_notes[id];
}

NoteItem NotesModel::getUsingUniqueId(int uniqueId) const {
    for(int i = 0; i < m_notes.count(); i++) {
        if(m_notes[i].m_id == uniqueId)
            return m_notes[i];
    }
    Q_ASSERT(false);
    return NoteItem();
}

int NotesModel::count() const {
    return m_notes.count();
}


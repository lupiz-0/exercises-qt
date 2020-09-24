#ifndef NOTESMODEL_H
#define NOTESMODEL_H

#include <QObject>



struct NoteItem {
    Q_GADGET
public:
    NoteItem() = default;
    NoteItem(int id_0, int x_0, int y_0, const QString& text_0): id(id_0), x(x_0), y(y_0), text(text_0) {}

    Q_PROPERTY(int id MEMBER id)
    Q_PROPERTY(int x MEMBER x)
    Q_PROPERTY(int y MEMBER y)
    Q_PROPERTY(QString text MEMBER text)

    int id;
    int x;
    int y;
    QString text;
};
Q_DECLARE_METATYPE(NoteItem)


class NotesModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int count READ count)
public:
    explicit NotesModel(QObject *parent = nullptr);

public slots:
    void addNote(const NoteItem& note);
    void removeNote(int id);
    NoteItem newNoteItem(int id, int x, int y, const QString& text);
    int getFreeUniqueId() const;
    NoteItem getUsingInternalArrayId(int id) const;
    NoteItem getUsingUniqueId(int uniqueId) const;

private:
    int count() const;
    bool isAnIdAlreadyUsed(int id) const;

    QVector<NoteItem> notes;
};

#endif // NOTESMODEL_H

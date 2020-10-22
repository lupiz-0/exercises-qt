#ifndef NOTESMODEL_H
#define NOTESMODEL_H

#include <QObject>



struct NoteItem {
    Q_GADGET
public:
    NoteItem() = default;
    NoteItem(int id, int x, int y, const QString& text): m_id(id), m_x(x), m_y(y), m_text(text) {}

    Q_PROPERTY(int id MEMBER m_id)
    Q_PROPERTY(int x MEMBER m_x)
    Q_PROPERTY(int y MEMBER m_y)
    Q_PROPERTY(QString text MEMBER m_text)

    int m_id;
    int m_x;
    int m_y;
    QString m_text;
};
Q_DECLARE_METATYPE(NoteItem)


class NotesModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)
public:
    explicit NotesModel(QObject *parent = nullptr);
    int count() const;

public slots:
    void addNote(const NoteItem& note);
    void removeNote(int id);
    NoteItem newNoteItem(int id, int x, int y, const QString& text);
    int getFreeUniqueId() const;
    NoteItem getUsingInternalArrayId(int id) const;
    NoteItem getUsingUniqueId(int uniqueId) const;

signals:
    void countChanged(int arg);

private:
    bool isAnIdAlreadyUsed(int id) const;

    QVector<NoteItem> m_notes;
};

#endif // NOTESMODEL_H

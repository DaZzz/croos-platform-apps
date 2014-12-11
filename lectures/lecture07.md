## Лекция 7 «Модель - Представление - Контроллер»

Лучше использовать Q_View классы а не Widgets.

QUndoView - стек Redo, Undo.
QStyledItemDelegate - стандарт; рисует с заданным стилем.

---

pModel->index(nRow, nCol, parentIndex); // Определяет элемент

Роли:
  DisplayRole - как отображать данные;
  EditRole - то что отображается в редакторе;
  DecorationRole - как должен отображаться в редакторе (обычные, окантованный);
  ToolTipRole - что отображается в тул-типе;
  StatusTipRole - что в статусной строке;


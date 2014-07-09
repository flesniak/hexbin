#include <QtGui>

class convert : public QWidget
{
Q_OBJECT

  public:
    convert();
  public slots:
    void slot_bin(void);
    void slot_oct(void);
    void slot_dec(void);
    void slot_hex(void);
  private:
    QLineEdit *edit_bin;
    QLineEdit *edit_oct;
    QLineEdit *edit_dec;
    QLineEdit *edit_hex;
    
    bool lock;
};

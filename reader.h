#ifndef READER_H
#define READER_H

#include "functions.h"
#include "alert.h"
#include "generaldialog.h"
#include "toast.h"
#include "quit.h"

#include <QWidget>
#include <QGraphicsScene>

using namespace std;

// ePUB & PDF scaling
namespace mupdf {
    inline bool convertRelativeValues;
    namespace epub {
        inline int fontSize;
        inline int width;
        inline int height;
        inline int epubPageNumber;
        inline QString fontSize_qstr;
        inline QString width_qstr;
        inline QString height_qstr;
        inline QString epubPageNumber_qstr;
    }
    namespace pdf {
        inline int width;
        inline int height;
        inline int relativeWidth;
        inline int relativeHeight;
        inline int pdfPageNumber;
        inline QString width_qstr;
        inline QString height_qstr;
        inline QString pdfPageNumber_qstr;
    }
}

namespace Ui {
class reader;
}

class reader : public QWidget
{
    Q_OBJECT

public:
    explicit reader(QWidget *parent = nullptr);
    ~reader();

    int split_total;
    int split_files_number;
    int page_number;
    int dictionary_position = 1;
    int pagesTurned = 0;
    int textAlignment;

    // -1 : Never refresh | 0 : Refresh every page | 1 : Refresh every 1 page. And so on...
    // Refresh every 3 pages is the default
    int pageRefreshSetting = 3;

    bool menubar_shown = false;
    bool nextdefinition_lock = false;
    bool is_epub = false;
    bool is_pdf = false;
    bool is_image = false;
    bool parser_ran = false;
    bool filematch_ran = false;
    bool neverRefresh = false;
    bool wakeFromSleep = false;
    bool remount = true;
    bool showTopbarWidget;
    bool wordwidgetLock;
    bool isNightModeActive;
    bool goToSavedPageDone;
    QString book_1;
    QString book_2;
    QString book_3;
    QString book_4;
    QString ittext;
    QString book_file;
    bool batt_status;
    QString selected_text;
    QString word;
    QString words; // Saved words
    QString letter;
    string selected_text_str;
    QString definition;
    QPixmap scaledChargingPixmap;
    QPixmap scaledHalfPixmap;
    QPixmap scaledFullPixmap;
    QPixmap scaledEmptyPixmap;
    QList<QString> content;
    QString epubPageContent;
    QString usbmsStatus;
    int pageNumberInt;
    int totalPagesInt;

    int setup_book(QString book, int i, bool run_parser);
    void checkwords();
    bool epub_file_match(QString file);
    void dictionary_lookup(string word, QString first_letter, int position);
    void save_word(string word, bool remove);
    void menubar_show();
    void menubar_hide();
    void wordwidget_show();
    void wordwidget_hide();
    void openLowBatteryDialog();
    void openCriticalBatteryAlertWindow();
    void convertMuPdfVars(int fileType);
    void refreshScreen();
    void setPageStyle(int fileType);
    void alignText(int alignment);
    void delay(int seconds);
    void openUsbmsDialog();
    QString setPageNumberLabelContent();
    void setupPageWidget();
    void getTotalEpubPagesNumber();
    void getTotalPdfPagesNumber();
    void setBitterFont();
    void setCrimsonProFont();
    void setIbarraFont();
    bool pdf_file_match(QString file);
    bool image_file_match(QString file);

private slots:
    void on_nextBtn_clicked();
    void on_previousBtn_clicked();
    void on_optionsBtn_clicked();
    void on_brightnessDecBtn_clicked();
    void on_brightnessIncBtn_clicked();
    void on_aboutBtn_clicked();
    void on_homeBtn_clicked();
    void on_fontChooser_currentIndexChanged(const QString &arg1);
    void on_alignLeftBtn_clicked();
    void on_alignCenterBtn_clicked();
    void on_alignRightBtn_clicked();
    void on_alignJustifyBtn_clicked();
    void on_infoCloseBtn_clicked();
    void on_previousDefinitionBtn_clicked();
    void on_nextDefinitionBtn_clicked();
    void on_saveWordBtn_clicked();
    void on_sizeSlider_valueChanged(int value);
    void writeconfig_pagenumber(bool persistent);
    void quit_restart();
    void on_text_selectionChanged();
    void on_nightModeBtn_clicked();
    void on_gotoBtn_clicked();
    void gotoPage(int pageNumber);
    void on_searchBtn_clicked();
    void searchRefreshScreen();
    void setupSearchDialog();
    void saveReadingSettings();
    void setupLocalSettingsEnvironment();
    void setupPng();
    void on_pdfScaleSlider_valueChanged(int value);
    void on_decreaseScaleBtn_clicked();
    void on_increaseScaleBtn_clicked();
    void openBookFileNative(QString book, bool relativePath);
    void showToast(QString messageToDisplay);
    void on_quitBtn_clicked();

signals:
    void openBookFile(QString book, bool relativePath);

private:
    Ui::reader * ui;
    alert * alertWindow;
    generalDialog * generalDialogWindow;
    toast * toastWindow;
    quit * quitWindow;
    QGraphicsScene * graphicsScene;
};

#endif // READER_H

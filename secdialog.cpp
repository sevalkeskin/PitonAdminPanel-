#include "secdialog.h"
#include "ui_secdialog.h"

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);
}

SecDialog::~SecDialog()
{
    delete ui;
}


void SecDialog::on_saveBtn_clicked()
{



        QUrl url( " " );
        QNetworkRequest request(url);
        request.setRawHeader( "Content-Type", "application/json" );

        QString name = ui->name->text();
        int Id = ui->Id->text().toInt();
        QString surname = ui->surname->text();
        QString RFID = ui->rfId->text();


      // will be created automatically when you open the file in a ReadWrite mode, not the file
       // QString fileName = "userinfo.json";
       // QFile file(fileName);
        //file.open(QIODevice::ReadWrite | QIODevice::Text);

        // the JSON data is written JSON file
        QJsonDocument jdc;
        QJsonObject obj;
        obj.insert("RFID",RFID);
        obj.insert("surname",surname);
        obj.insert("name",name);
        obj.insert("Id",Id);
        jdc.setObject(obj);
        QByteArray json = jdc.toJson( QJsonDocument::Compact );
        QNetworkAccessManager manager;
        QNetworkReply *reply = manager.post( request, json );

        connect(manager, SIGNAL(finished(QNetworkReply*)), this,SLOT(slotRequestFinished(QNetworkReply *reply)));
        manager->post(request, json);


       // file.resize (0); // empty file
       //file.write(jdc.toJson());
       // file.flush();
       // file.close();

}


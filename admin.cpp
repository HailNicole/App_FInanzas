#include "admin.h"
#include "ui_admin.h"
#include "QDebug"

Admin::Admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
    cargar_admin();
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_btn_acceder_clicked()
{
    QMapIterator<QString, QString> i(usuario_admin);
        while (i.hasNext())
        {
            i.next();
            if(i.key() == ui->in_usadmin->text() && (i.value()) == ui->in_conadmin->text())
            {
                Usuarios_admin *welcome = new Usuarios_admin();
                this->close();
                welcome->exec();
                break;
            }
        }
        QMessageBox::warning(this, tr("Acceso"), tr("Usuario y/o Contraseña Incorrecta"), tr("Aceptar"));

}
//admin_administrador@outlook.com
//gatitoblade
void Admin::on_btn_crear_clicked()
{
    if(usuario_admin.empty()){
        Registrar_usuario *reg = new Registrar_usuario(this);
            reg->setWindowTitle(tr("Registrar Usuario"));
            int res = reg->exec();
            if (res == QDialog::Rejected){
                return;
            }

            if(!reg->getUsuarios().isEmpty()){
                QMapIterator<QString, QString> i(reg->getUsuarios());
                    i.next();
                    usuario_admin.insert(i.key(), i.value());
            }
            m_controlador->Guardar_Admin(usuario_admin);
    }else{
        QMessageBox::warning(this, tr("Administrador"), tr("Ya existe una cuenta creada"), tr("Aceptar"));
        return;
    }
}

void Admin::cargar_admin()
{
    // Verificar si el archivo existe
   QFile adm(tr("admin.csv"));
    if (!adm.exists())
        return;

    // cargar datos
    if (adm.open(QFile::ReadOnly)) {
        QTextStream entrada(&adm);
        while(!entrada.atEnd()){
            QString linea = entrada.readLine();
            QStringList datos = linea.split(";");
             usuario_admin.insert(datos[USUARIO],datos[CONTRASENIA]);
             qDebug()<<usuario_admin;
        }
        adm.close();
    }
}
void Admin::on_actionPrincipal_triggered()
{
    this->close();
    Principal *prince = new Principal(this);
    prince->show();
}


void Admin::on_actionLogin_triggered()
{
    this->close();
    Acceso *acces = new Acceso(this);
    acces->show();
}


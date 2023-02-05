#include "objeto_registro.h"


Objeto_registro::Objeto_registro(QObject *parent)
    : QObject{parent}
{

}

Objeto_registro::Objeto_registro(const QString &fecha, const QString &miembro, const QString &descripcion, Tipo &tipo, const QString &categoria, double valor) :
    m_fecha(fecha),
    m_miembro(miembro),
    m_descripcion(descripcion),
    m_tipo(tipo),
    m_categoria(categoria),
    m_valor(valor)
{}

const QString &Objeto_registro::fecha() const
{
    return m_fecha;
}

void Objeto_registro::setFecha(const QString &newFecha)
{
    m_fecha = newFecha;
}

const QString &Objeto_registro::miembro() const
{
    return m_miembro;
}

void Objeto_registro::setMiembro(const QString &newMiembro)
{
    m_miembro = newMiembro;
}

const QString &Objeto_registro::descripcion() const
{
    return m_descripcion;
}

void Objeto_registro::setDescripcion(const QString &newDescripcion)
{
    m_descripcion = newDescripcion;
}

const Tipo &Objeto_registro::tipo() const
{
    return m_tipo;
}

void Objeto_registro::setTipo(Tipo &newTipo)
{
    m_tipo = newTipo;
}

const QString &Objeto_registro::categoria() const
{
    return m_categoria;
}

void Objeto_registro::setCategoria(const QString &newCategoria)
{
    m_categoria = newCategoria;
}

double Objeto_registro::valor() const
{
    return m_valor;
}

void Objeto_registro::setValor(double newValor)
{
    m_valor = newValor;
}

QString Objeto_registro::tipo2string()
{
    switch (m_tipo) {
    case Tipo::Ingreso:
        return tr("Ingreso");
        break;
    case Tipo::Egreso:
        return tr("Egreso");
        break;
    default:
        return "";
    }
}

#include "enginespinoption.h"

EngineSpinOption::EngineSpinOption()
	: EngineOption(QString())
{
}

EngineSpinOption::EngineSpinOption(const QString& name,
				   const QVariant& value,
				   const QVariant& defaultValue,
				   int min,
				   int max)
	: EngineOption(name, value, defaultValue),
	  m_min(min),
	  m_max(max)
{
}

EngineOption* EngineSpinOption::copy() const
{
	return new EngineSpinOption(*this);
}

bool EngineSpinOption::isValid(const QVariant& value) const
{
	if (m_min > m_max)
		return false;

	bool ok = false;
	int tmp = value.toInt(&ok);
	if (!ok
	||  ((m_min != 0 || m_max != 0) && (tmp < m_min || tmp > m_max)))
		return false;

	return true;
}

int EngineSpinOption::min() const
{
	return m_min;
}

int EngineSpinOption::max() const
{
	return m_max;
}

void EngineSpinOption::setMin(int min)
{
	m_min = min;
}

void EngineSpinOption::setMax(int max)
{
	m_max = max;
}

QVariant EngineSpinOption::toVariant() const
{
	return QVariant::fromValue(*this);
}

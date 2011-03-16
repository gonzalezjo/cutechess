#ifndef ENGINEBUTTONOPTION_H
#define ENGINEBUTTONOPTION_H

#include "engineoption.h"

class LIB_EXPORT EngineButtonOption : public EngineOption
{
	public:
		EngineButtonOption();
		EngineButtonOption(const QString& name);

		EngineOption* copy() const;

		bool isValid(const QVariant& value) const;
		QVariant toVariant() const;
};

Q_DECLARE_METATYPE(EngineButtonOption)

#endif // ENGINEBUTTONOPTION_H

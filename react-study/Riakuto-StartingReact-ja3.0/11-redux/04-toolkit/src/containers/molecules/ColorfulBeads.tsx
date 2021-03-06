import React, { FC } from 'react';
import { useSelector } from 'react-redux';

import ColorfulBeads from 'components/molecules/ColorfulBeads';
import { CounterState } from 'features/counter';

const EnhancedColorfulBeads: FC = () => {
  const count = useSelector<CounterState, number>((state) => state.count);

  return <ColorfulBeads count={count} />;
};

export default EnhancedColorfulBeads;
